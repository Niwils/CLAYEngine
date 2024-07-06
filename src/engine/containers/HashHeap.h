/*!
 * The CLAYEngine project.
 *
 * \file /src/engine/containers/HashHeap.h
 *
 * \brief A HashHeap is a hashmap container.
 */

/*
 * CHANGELOG:
 * 20/12/2020: File creation (NG)
 */
#ifndef FACTORYBUILDER_HASHHEAP_H
#define FACTORYBUILDER_HASHHEAP_H

#include <Types.h>

/*!
* \brief A HashHeapCell is a node of the HashHeap.
*/
template <typename J, typename K> class HashHeapCell
{
public:
	/*!
	* \brief HashHeapCell constructor.
	* \param _hash The cell hash. Note this must not be a pointer.
	* \param _pObj Pointer to the object that must be carried by the HashMap.
	*/
	HashHeapCell(J _hash, K *_pObj)
	: m_pLeft(nullptr)
	, m_pRight(nullptr)
	, m_depth(0U)
	{
		m_hash = _hash;
		m_pObj = _pObj;
	}

	/*!
	* \brief HashHeapCell destructor.
	*/
	~HashHeapCell()
	{

	}

	/*!
	* \brief Add the object to a leaf cell.
	*
	* \param _hash The object hash (no pointer allowed)
	* \param _pObj Pointer to the object that must be put in the leaf cell.
	* \return The hash heap depth of the current HashHeapCell.
	*/
	s_HashHeapDepth addObj(J _hash, K *_pObj)
	{
		s_HashHeapDepth l_left = 0U;
		s_HashHeapDepth l_right = 0U;

		if(m_hash < _hash)
		{

			if (nullptr != m_pRight)
			{
				l_right = m_pRight->addObj(_hash, _pObj);

				if(2 == l_right)
				{
					if(1 == m_pRight->getRightCell()->getDeltaDepth())
					{
						m_pRight = rotateLeft(m_pRight);
					}
					else if(-1 == m_pRight->getRightCell()->getDeltaDepth())
					{
						HashHeapCell<J, K> *l_secondDegreeRightSon = m_pRight->getRightCell();

						l_secondDegreeRightSon = rotateRight(l_secondDegreeRightSon);

						m_pRight->setRightCell(l_secondDegreeRightSon);

						m_pRight = rotateLeft(m_pRight);
					}
				}
				else if(-2 == l_right)
				{
					if(-1 == m_pRight->getLeftCell()->getDeltaDepth())
					{
						m_pRight = rotateRight(m_pRight);
					}
					else if(1 == m_pRight->getLeftCell()->getDeltaDepth())
					{
						HashHeapCell<J, K> *l_secondDegreeLeftSon = m_pRight->getLeftCell();

						l_secondDegreeLeftSon = rotateLeft(l_secondDegreeLeftSon);

						m_pRight->setLeftCell(l_secondDegreeLeftSon);

						m_pRight = rotateRight(m_pRight);
					}
				}
			}
			else
			{
				m_pRight = new HashHeapCell<J, K>(_hash, _pObj);
				m_pRight->setDepth(m_depth+1);
			}

		}
		else
		{
			if (nullptr != m_pLeft)
			{
				l_left = m_pLeft->addObj(_hash, _pObj)+1;

				if(2 == l_left)
				{
					if(1 == m_pLeft->getRightCell()->getDeltaDepth())
					{
						m_pLeft = rotateLeft(m_pLeft);
					}
					else if(-1 == m_pLeft->getRightCell()->getDeltaDepth())
					{
						HashHeapCell<J, K> *l_secondDegreeRightSon = m_pLeft->getRightCell();

						l_secondDegreeRightSon = rotateRight(l_secondDegreeRightSon);

						m_pLeft->setRightCell(l_secondDegreeRightSon);

						m_pLeft = rotateLeft(m_pLeft);
					}
				}
				else if(-2 == l_left)
				{
					if(-1 == m_pLeft->getLeftCell()->getDeltaDepth())
					{
						m_pLeft = rotateRight(m_pLeft);
					}
					else if(1 == m_pLeft->getLeftCell()->getDeltaDepth())
					{
						HashHeapCell<J, K> *l_secondDegreeLeftSon = m_pLeft->getLeftCell();

						l_secondDegreeLeftSon = rotateLeft(l_secondDegreeLeftSon);

						m_pLeft->setLeftCell(l_secondDegreeLeftSon);

						m_pLeft = rotateRight(m_pLeft);
					}
				}
			}
			else
			{
				m_pLeft = new HashHeapCell<J, K>(_hash, _pObj);
				m_pLeft->setDepth(m_depth+1);
			}
		}

		if(nullptr != m_pLeft)
		{
			l_left = m_pLeft->getDepth();
		}
		else
		{
			l_left = 0;
		}

		if(nullptr != m_pRight)
		{
			l_right = m_pRight->getDepth();
		}
		else
		{
			l_right = 0;
		}

		m_deltaDepth = (l_right - l_left - m_depth);

		return m_deltaDepth;
	}

	/*!
	* \brief Returns the Object of the cell.
	* \return The Cell object.
	*/
	K *getObj()
	{
		return m_pObj;
	}

	J getHash()
	{
		return m_hash;
	}

	J getLeftHash()
	{
		return m_pLeft->getHash();
	}

	HashHeapCell *getLeftCell()
	{
		return m_pLeft;
	}

	void setLeftCell(HashHeapCell<J, K> *_cell)
	{
		m_pLeft=_cell;
	}

	void setRightCell(HashHeapCell<J, K> *_cell)
	{
		m_pRight=_cell;
	}

	HashHeapCell *getRightCell()
	{
		return m_pRight;
	}

	J getRightHash()
	{
		return m_pLeft->getHash();
	}

	void setDeltaDepth(s_HashHeapDepth _depth)
	{
		m_deltaDepth = _depth;
	}

	s_HashHeapDepth getDeltaDepth()
	{

		return m_deltaDepth;
	}

	s_HashHeapDepth getDepth()
	{
		s_HashHeapDepth l_ret = 0U;

		s_HashHeapDepth l_left = 0U;
		s_HashHeapDepth l_right = 0U;

		if (nullptr != m_pLeft)
		{
			l_left = m_pLeft->getDepth();
		}
		else
		{
			l_left = 0;
		}

		if (nullptr != m_pRight)
		{
			l_right = m_pRight->getDepth();
		}
		else
		{
			l_right = 0;
		}

		if((0 < l_left) || (0 < l_right))
		{
			l_ret = (l_right > l_left) ? l_right : l_left;
		}
		else
		{
			l_ret = m_depth;
		}

		return l_ret;
	}

	K *getObj(J _hash)
	{
		if(m_hash == _hash)
		{
			return m_pObj;
		}
		else
		{
			if(m_pLeft->getHash() >= _hash)
			{

			}
		}
	}

	void setDepth(s_HashHeapDepth _depth)
	{
		m_depth = _depth;

		if(nullptr != m_pLeft)
		{
			m_pLeft->setDepth(m_depth + 1);
		}

		if(nullptr != m_pRight)
		{
			m_pRight->setDepth(m_depth + 1);
		}
	}

	s_HashHeapDepth getCellDepth()
	{
		return m_depth;
	}

	static HashHeapCell<J, K> *rotateLeft(HashHeapCell<J, K> *_cell)
	{
		HashHeapCell<J, K> *l_rightSon = _cell->getRightCell();
		HashHeapCell<J, K> *l_rightSonLeftCell = l_rightSon->getLeftCell();
		_cell->setRightCell(l_rightSonLeftCell);

		l_rightSon->setLeftCell(_cell);

		_cell->setDeltaDepth(0);
		l_rightSon->setDeltaDepth(0);

		s_HashHeapDepth l_prevDepth = _cell->getCellDepth();
		_cell->setDepth(l_rightSon->getCellDepth());
		l_rightSon->setDepth(l_prevDepth);

		return l_rightSon;
	}

	static HashHeapCell<J, K> *rotateRight(HashHeapCell<J, K> *_cell)
	{
		HashHeapCell<J, K> *l_leftSon = _cell->getLeftCell();
		HashHeapCell<J, K> *l_leftSonRightCll = l_leftSon->getRightCell();
		_cell->setLeftCell(l_leftSonRightCll);

		l_leftSon->setRightCell(_cell);

		_cell->setDeltaDepth(0);
		l_leftSon->setDeltaDepth(0);

		s_HashHeapDepth l_prevDepth = _cell->getCellDepth();
		_cell->setDepth(l_leftSon->getCellDepth());
		l_leftSon->setDepth(l_prevDepth);

		return l_leftSon;
	}

private:
	J m_hash;
	K *m_pObj;
	HashHeapCell *m_pLeft;
	HashHeapCell *m_pRight;

	s_HashHeapDepth m_depth;
	s_HashHeapDepth m_deltaDepth;
};

template <typename J, typename K> class HashHeap
{
public:
	HashHeap()
	: m_top(nullptr)
	, m_depth(0)
	{
	}

	~HashHeap()
	{

	}

	void addObj(J _hash, K *_obj)
	{
		HashHeapCell<J, K> *l_newCell = new HashHeapCell<J, K>(_hash, _obj);

		HashHeapCell<J, K> *l_runner = m_top;
		HashHeapCell<J, K> *l_topRunner = nullptr;

		s_HashHeapDepth l_depth = 0U;
		if(nullptr == m_top)
		{
			m_top = l_newCell;
		}
		else
		{
			s_HashHeapDepth  l_depth = m_top->addObj(_hash, _obj);

			if(2 == l_depth)
			{
				if(1 == m_top->getRightCell()->getDeltaDepth())
				{
					m_top = HashHeapCell<J, K>::rotateLeft(m_top);
				}
				else if(-1 == m_top->getRightCell()->getDeltaDepth())
				{
					HashHeapCell<J, K> *l_secondDegreeRightSon = m_top->getRightCell();

					l_secondDegreeRightSon = HashHeapCell<J, K>::rotateRight(l_secondDegreeRightSon);

					m_top->setRightCell(l_secondDegreeRightSon);

					m_top = HashHeapCell<J, K>::rotateLeft(m_top);
				}
			}
			else if(-2 == l_depth)
			{
				if(-1 == m_top->getLeftCell()->getDeltaDepth())
				{
					m_top = HashHeapCell<J, K>::rotateRight(m_top);
				}
				else if(1 == m_top->getLeftCell()->getDeltaDepth())
				{
					HashHeapCell<J, K> *l_secondDegreeLeftSon = m_top->getLeftCell();

					l_secondDegreeLeftSon = HashHeapCell<J, K>::rotateLeft(l_secondDegreeLeftSon);

					m_top->setLeftCell(l_secondDegreeLeftSon);

					m_top = HashHeapCell<J, K>::rotateRight(m_top);
				}
			}
		}
	}

	K *getObj(J _hash)
	{
		K *l_ret = nullptr;

		if(m_top->getHash() == _hash)
		{
			return m_top->getObj();
		}
		else
		{
			HashHeapCell<J, K> *l_runner = m_top;

			while((nullptr != l_runner) && (nullptr == l_ret))
			{
				if(_hash == l_runner->getHash())
				{
					l_ret = l_runner->getObj();
				}
				else
				{
					if(l_runner->getHash() > _hash)
					{
						l_runner = l_runner->getLeftCell();
					}
					else
					{
						l_runner = l_runner->getRightCell();
					}
				}
			}
		}

		return l_ret;
	}

	K *removeObj(J _hash)
	{
		K *l_ret = nullptr;

		if(m_top->getHash() == _hash)
		{
			l_ret = m_top->getObj();
			delete m_top;
		}
		else
		{
			HashHeapCell<J, K> *l_runner = m_top;
			HashHeapCell<J, K> *l_runnerTop = m_top;
			HashHeapCell<J, K> *l_found = nullptr;
			bool isLeftSon = false;

			while((nullptr != l_runner) && (nullptr == l_found))
			{
				if(_hash == l_runner->getHash())
				{
					l_found = l_runner;
				}
				else
				{
					l_runnerTop = l_runner;
					if(l_runner->getHash() > _hash)
					{
						l_runner = l_runner->getLeftCell();
						isLeftSon = true;
					}
					else
					{
						l_runner = l_runner->getRightCell();
						isLeftSon = false;
					}
				}
			}

			if(nullptr != l_found)
			{
				if((nullptr == l_runner->getLeftCell())
					&& (nullptr == l_runner->getRightCell())
					)
				{
					l_ret = l_runner->getObj();

					if(true == isLeftSon)
					{
						l_runnerTop->setLeftCell(nullptr);
					}
					else
					{
						l_runnerTop->setRightCell(nullptr);
					}
					delete l_runner;
				}
				else if(nullptr == l_runner->getLeftCell())
				{
					l_ret = l_runner->getObj();

					if(true == isLeftSon)
					{
						l_runnerTop->setLeftCell(l_runner->getRightCell());
					}
					else
					{
						l_runnerTop->setRightCell(l_runner->getRightCell());
					}

					l_runner->getRightCell()->setDepth(l_runnerTop->getDepth()+1);

					delete l_runner;
				}
				else if(nullptr == l_runner->getRightCell())
				{
					l_ret = l_runner->getObj();

					if(true == isLeftSon)
					{
						l_runnerTop->setLeftCell(l_runner->getLeftCell());
					}
					else
					{
						l_runnerTop->setRightCell(l_runner->getLeftCell());
					}

					l_runner->getLeftCell()->setDepth(l_runnerTop->getDepth()+1);

					delete l_runner;
				}
				else // Node has both leafs...
				{

				}
			}
		}

		return l_ret;
	}

	HashHeapCell<J, K> *getTop()
	{
		return m_top;
	}


private:
	HashHeapCell<J, K> *m_top;

	s_HashHeapDepth m_depth;
};
#endif //FACTORYBUILDER_HASHHEAP_H
