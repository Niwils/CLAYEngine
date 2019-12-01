/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/containers/ObjList.h
 *
 * \brief A list container.
 */

/*
 * CHANGELOG:
 * 30/11/2019: File creation (NG)
 */

#ifndef _ENGINE_CONTAINERS_OBJLIST_H
#define _ENGINE_CONTAINERS_OBJLIST_H

template <class K> class ObjListCell
{
public:
	void setObj(K *_obj)
	{
		m_Obj = _obj;
	}

	K *getObj()
	{
		return m_Obj;
	}

	ObjListCell *getNext()
	{
		return m_Next;
	}

	void setNext(ObjListCell *_next)
	{
		m_Next = _next;
	}

private:
	K *m_Obj;
	ObjListCell *m_Next;
};

template <class K> class ObjList
{
	ObjListCell<K> *m_Start;
	ObjListCell<K> *m_Cursor;
	ObjListCell<K> *m_End;

	void addObject(K *_obj)
	{
		ObjListCell<K> l_cell = new ObjListCell<K>();

		if(nullptr != l_cell) // TODO raise error or proceed to assert here instead?
		{
			if(nullptr == m_Start)
			{
				l_cell->setObj(_obj);
				m_Start = l_cell;
				m_End = l_cell;
				m_Cursor = m_Start;
			}
			else
			{
				m_End->setNext(l_cell);
				m_End = m_End->getNext();
			}
		}
	}

	K *getFirst()
	{
		if(nullptr != m_Start)
		{
			return m_Start->getObj();
		}
		else
		{
			return nullptr;
		}

	}

	K *iterate()
	{
		m_Cursor->getNext();

		if(nullptr != m_Cursor)
		{
			return m_Cursor->getObj();
		}
		else
		{
			return nullptr;
		}
	}

	// TODO add remove and other useful functions
};

#endif /* End _ENGINE_CONTAINERS_OBJLIST_H */
