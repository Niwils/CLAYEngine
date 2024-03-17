/**
 * The CLAYEngine project.
 *
 * @file /src/engine/graph/IGraph.h
 *
 * @brief A TransportationGraph contains all transportation nodes and edges for the item transportation.
 */

/*
 * CHANGELOG:
 * 20/12/2020: File creation (NG)
 */
#ifndef FACTORYBUILDER_HASHHEAP_H
#define FACTORYBUILDER_HASHHEAP_H

#include <Types.h>

template <typename J, typename K> class HashHeapCell
{
public:
	HashHeapCell(J _hash, K *_obj)
	: m_left(nullptr)
	, m_right(nullptr)
	, m_depth(0U)
	{
		m_hash = _hash;
		m_obj = _obj;
	}

	~HashHeapCell()
	{

	}

	s_HashHeapDepth addObj(J _hash, K *_obj)
	{
		s_HashHeapDepth l_left = 0U;
		s_HashHeapDepth l_right = 0U;

		if(m_hash < _hash)
		{

			if (nullptr != m_right)
			{
				l_right = m_right->addObj(_hash, _obj);

				if(2 == l_right)
				{
					if(1 == m_right->getRightCell()->getDeltaDepth())
					{
						m_right = rotateLeft(m_right);
					}
					else if(-1 == m_right->getRightCell()->getDeltaDepth())
					{
						HashHeapCell<J, K> *l_secondDegreeRightSon = m_right->getRightCell();

						l_secondDegreeRightSon = rotateRight(l_secondDegreeRightSon);

						m_right->setRightCell(l_secondDegreeRightSon);

						m_right = rotateLeft(m_right);
					}
				}
				else if(-2 == l_right)
				{
					if(-1 == m_right->getLeftCell()->getDeltaDepth())
					{
						m_right = rotateRight(m_right);
					}
					else if(1 == m_right->getLeftCell()->getDeltaDepth())
					{
						HashHeapCell<J, K> *l_secondDegreeLeftSon = m_right->getLeftCell();

						l_secondDegreeLeftSon = rotateLeft(l_secondDegreeLeftSon);

						m_right->setLeftCell(l_secondDegreeLeftSon);

						m_right = rotateRight(m_right);
					}
				}
			}
			else
			{
				m_right = new HashHeapCell<J, K>(_hash, _obj);
				m_right->setDepth(m_depth+1);
			}

		}
		else
		{
			if (nullptr != m_left)
			{
				l_left = m_left->addObj(_hash, _obj)+1;

				if(2 == l_left)
				{
					if(1 == m_left->getRightCell()->getDeltaDepth())
					{
						m_left = rotateLeft(m_left);
					}
					else if(-1 == m_left->getRightCell()->getDeltaDepth())
					{
						HashHeapCell<J, K> *l_secondDegreeRightSon = m_left->getRightCell();

						l_secondDegreeRightSon = rotateRight(l_secondDegreeRightSon);

						m_left->setRightCell(l_secondDegreeRightSon);

						m_left = rotateLeft(m_left);
					}
				}
				else if(-2 == l_left)
				{
					if(-1 == m_left->getLeftCell()->getDeltaDepth())
					{
						m_left = rotateRight(m_left);
					}
					else if(1 == m_left->getLeftCell()->getDeltaDepth())
					{
						HashHeapCell<J, K> *l_secondDegreeLeftSon = m_left->getLeftCell();

						l_secondDegreeLeftSon = rotateLeft(l_secondDegreeLeftSon);

						m_left->setLeftCell(l_secondDegreeLeftSon);

						m_left = rotateRight(m_left);
					}
				}
			}
			else
			{
				m_left = new HashHeapCell<J, K>(_hash, _obj);
				m_left->setDepth(m_depth+1);
			}
		}

		if(nullptr != m_left)
		{
			l_left = m_left->getDepth();
		}
		else
		{
			l_left = 0;
		}

		if(nullptr != m_right)
		{
			l_right = m_right->getDepth();
		}
		else
		{
			l_right = 0;
		}

		m_deltaDepth = (l_right - l_left - m_depth);

		return m_deltaDepth;
	}

	K *getObj()
	{
		return m_obj;
	}

	J getHash()
	{
		return m_hash;
	}

	J getLeftHash()
	{
		return m_left->getHash();
	}

	HashHeapCell *getLeftCell()
	{
		return m_left;
	}

	void setLeftCell(HashHeapCell<J, K> *_cell)
	{
		m_left=_cell;
	}

	void setRightCell(HashHeapCell<J, K> *_cell)
	{
		m_right=_cell;
	}

	HashHeapCell *getRightCell()
	{
		return m_right;
	}

	J getRightHash()
	{
		return m_left->getHash();
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

		if (nullptr != m_left)
		{
			l_left = m_left->getDepth();
		}
		else
		{
			l_left = 0;
		}

		if (nullptr != m_right)
		{
			l_right = m_right->getDepth();
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
			return m_obj;
		}
		else
		{
			if(m_left->getHash() >= _hash)
			{

			}
		}
	}

	void setDepth(s_HashHeapDepth _depth)
	{
		m_depth = _depth;

		if(nullptr != m_left)
		{
			m_left->setDepth(m_depth + 1);
		}

		if(nullptr != m_right)
		{
			m_right->setDepth(m_depth + 1);
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
	K *m_obj;
	HashHeapCell *m_left;
	HashHeapCell *m_right;

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
			return m_top;
		}
		else
		{
			HashHeapCell<J, K> *l_runner = m_top;

			while((nullptr != l_runner) && (nullptr == l_ret))
			{
				if(_hash == l_runner->getHash())
				{
					l_ret = l_runner;
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
