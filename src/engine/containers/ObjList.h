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
	ObjListCell()
	: m_Obj(nullptr)
	, m_Next(nullptr)
	{

	}

	~ObjListCell()
	{
		// Currently, do nothing as m_Next and m_Obj are managed separately.
	}

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
public:

	ObjList()
	: m_Start(nullptr)
	, m_Cursor(nullptr)
	, m_End(nullptr)
	{

	}

	~ObjList()
	{
		ObjListCell<K> *l_cursor = m_Start;
		ObjListCell<K> *l_cursor_next = m_Start->getNext();

		while(nullptr != l_cursor)
		{
			delete l_cursor;
			l_cursor = l_cursor_next;

			if(nullptr != l_cursor_next)
			{
				l_cursor_next = l_cursor_next->getNext();
			}
		}
		m_Cursor = nullptr;
		m_End = nullptr;
	}

	void addObject(K *_obj)
	{
		ObjListCell<K> *l_cell = new ObjListCell<K>();

		if(nullptr != l_cell) // TODO raise error or proceed to assert here instead?
		{
			l_cell->setObj(_obj);

			if(nullptr == m_Start)
			{
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
		K *l_obj = nullptr;

		if(nullptr != m_Cursor)
		{
			l_obj = m_Cursor->getObj();
			m_Cursor = m_Cursor->getNext();
		}

		return l_obj;
	}

	K *removeFirst()
	{
		K *l_element = nullptr;

		if(nullptr != m_Start)
		{
			ObjListCell<K> *l_cursor = m_Start;
			l_element = l_cursor->getObj();
			if(m_Start == m_Cursor)
			{
				m_Cursor = m_Start->getNext();
			}

			if(m_Start == m_End)
			{
				m_End = m_Start->getNext(); // i.e. shall return nullptr.
			}

			m_Start = m_Start->getNext();

			delete l_cursor;
		}

		return l_element;
	}

	K *removeObject(K *_obj)
	{
		K *l_obj = nullptr;
		ObjListCell<K> *l_cursor = m_Start;
		ObjListCell<K> *l_cursor_prev = nullptr;

		while(nullptr != l_cursor)
		{
			if(_obj == l_cursor->getObj())
			{
				l_obj = l_cursor->getObj();

				if(nullptr != l_cursor_prev) // if l_cursor is not pointing the first element
				{
					l_cursor_prev->setNext(l_cursor->getNext());

					if(m_End == l_cursor)
					{
						m_End = l_cursor_prev;
					}

					if(m_Cursor == l_cursor)
					{
						m_Cursor = l_cursor_prev;
					}
				}
				else
				{
					m_Start = l_cursor->getNext();

					if(m_Cursor == l_cursor)
					{
						m_Cursor = m_Start; // if only one element, shall set to nullptr.
					}

					if(m_End == l_cursor)
					{
						m_End = m_Start; // as only one element, shall be set to nullptr.
					}
				}

				delete l_cursor;
			}
			else
			{
				l_cursor_prev = l_cursor;
				l_cursor = l_cursor->getNext();
			}
		}

		return l_obj;
	}
private:
	ObjListCell<K> *m_Start;
	ObjListCell<K> *m_Cursor;
	ObjListCell<K> *m_End;
};

#endif /* End _ENGINE_CONTAINERS_OBJLIST_H */
