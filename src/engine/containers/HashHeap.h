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
	, m_top(nullptr)
	{
		m_hash = _hash;
		m_obj = _obj;
	}

	~HashHeapCell()
	{

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

	void setTopCell(HashHeapCell<J, K> *_cell)
	{
		m_top = _cell;
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

	s_HashHeapDepth getLeftDepth()
	{
		if (nullptr != m_left)
		{
			return (m_left->getLeftDepth() + 1);
		}
		else
		{
			return 1;
		}
	}

	s_HashHeapDepth getRightDepth()
	{
		if (nullptr != m_right)
		{
			return (m_right->getLeftDepth() + 1);
		}
		else
		{
			return 1;
		}
	}

	void sortCells()
	{
		HashHeapCell<J, K> *l_oldTopCell = m_top;
		while(nullptr != l_oldTopCell)
		{
			if(m_hash > m_top->getHash())
			{
				HashHeapCell<J, K> *l_oldTopLeftCell = m_top->getLeftCell();
				HashHeapCell<J, K> *l_oldTopRightCell = m_top->getRightCell();
				l_oldTopCell->setLeftCell(m_left);
				l_oldTopCell->setRightCell(m_right);

				if(l_oldTopLeftCell == this)
				{
					m_left = l_oldTopCell;
					m_right = l_oldTopRightCell;
				}
				else
				{
					m_left = l_oldTopLeftCell;

					if(l_oldTopRightCell == this)
					{
						m_right = l_oldTopCell;
					}
					else
					{
						m_left = l_oldTopRightCell; // Should never happen. TODO assert here?
					}
				}

				m_top = l_oldTopCell->getTopCell();
				l_oldTopCell->setTopCell(this);
				l_oldTopCell = m_top;
			}
			else
			{
				l_oldTopCell = nullptr;
			}
		}
	}

	HashHeapCell *hasLeafAvailable(s_HashHeapDepth _remDepth, s_HashHeapDepth *_freeCellDepth)
	{
		if(0 < _remDepth)
		{
			if(nullptr == m_left)
			{
				*_freeCellDepth = 1U;
				return this;
			}
			else
			{
				if(nullptr == m_right)
				{
					*_freeCellDepth = 1U;
					return this;
				}
				else
				{
					s_HashHeapDepth l_leftDepth = 0U;
					s_HashHeapDepth l_rightDepth = 0U;

					HashHeapCell *l_leftCell = m_left->hasLeafAvailable(_remDepth-1, &l_leftDepth);
					HashHeapCell *l_rightCell = m_right->hasLeafAvailable(_remDepth-1, &l_rightDepth);

					if(nullptr != l_leftCell)
					{
						if(nullptr != l_rightCell)
						{
							if(l_leftDepth > l_rightDepth)
							{
								*_freeCellDepth = l_rightDepth+1;
								return l_rightCell;
							}
							else
							{
								*_freeCellDepth = l_leftDepth+1;
								return l_leftCell;
							}
						}
						else
						{
							*_freeCellDepth = *_freeCellDepth + l_leftDepth;
							return l_leftCell;
						}
					}
					else
					{
						if(nullptr != l_rightCell)
						{
							*_freeCellDepth = *_freeCellDepth + l_rightDepth;
							return l_rightDepth;
						}
						else
						{
							return nullptr;
						}
					}
				}
			}
		}
		else
		{
			return nullptr;
		}
	}

private:
	J m_hash;
	K *m_obj;
	HashHeapCell *m_top;
	HashHeapCell *m_left;
	HashHeapCell *m_right;
};

template <typename J, typename K> class HashHeap
{
public:
	HashHeap()
	{
	}

	~HashHeap()
	{

	}

	void addObj(J _hash, K *_obj)
	{
		HashHeapCell<J, K> l_newCell = new HashHeap<J, K>(_hash, _obj);

		if(nullptr == m_top)
		{
			m_top = l_newCell;
			m_depth++;
		}
		else
		{
			s_HashHeapDepth l_depth;
			HashHeapCell<J,K> *l_cell = m_top->hasLeafAvailable(m_depth);
			if(nullptr == l_cell)
			{
				m_depth++;
				l_cell = m_top->hasLeafAvailable(m_depth);
			}

			l_cell->setTopCell(l_newCell);

			if(nullptr == l_cell->getLeftCell())
			{
				l_cell->setLeftCell(l_newCell);
			}
			else
			{
				l_cell->setRightCell(l_newCell);
			}

			l_newCell->sortCells();
		}
	}


private:
	HashHeapCell<J, K> *m_top;

	s_HashHeapDepth m_depth;
};
#endif //FACTORYBUILDER_HASHHEAP_H
