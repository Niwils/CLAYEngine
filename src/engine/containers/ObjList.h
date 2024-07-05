/*!
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

/*!
* \brief A cell of the ObjList list.
*/
template <class K> class ObjListCell
{
public:
	/*!
	* \brief The ObjListCell constructor.
	*/
	ObjListCell()
	: m_pObj(nullptr)
	, m_pNext(nullptr)
	{

	}

	/*!
	* \brief The ObjListCell destructor.
	*/
	~ObjListCell()
	{
		// Currently, do nothing as m_Next and m_Obj are managed separately.
	}

	/*!
	* \brief Setter for the ObjListCell content.
	* \param _pObj Pointer to the object to be set within the cell.
	*/
	void setObj(K *_pObj)
	{
		m_pObj = _pObj;
	}

	/*!
	* \brief Getter for the ObjListCell content.
	* \return Pointer to the object within the cell.
	*/
	K *getObj()
	{
		return m_pObj;
	}

	/*!
	* \brief Return the next ObjListCell in the list.
	* \return Pointer to the next ObjListCell.
	*/
	ObjListCell *getNext()
	{
		return m_pNext;
	}

	/*!
	* \brief Setter of the next ObjListCell in the list.
	* \param _pNext Pointer to the next ObjListCell.
	*/
	void setNext(ObjListCell *_pNext)
	{
		m_pNext = _pNext;
	}

private:
	/*!
	* \brief Pointer to the ObjCellList content.
	*/
	K *m_pObj;

	/*!
	* \brief Pointer to the next ObjCellList.
	*/
	ObjListCell *m_pNext;
};

/*!
* \brief A daisy-chained list. Access to the start and the end of the list is o(1)
*/
template <class K> class ObjList
{
public:
	/*!
	* \brief The ObjList constructor.
	*/
	ObjList()
	: m_pStart(nullptr)
	, m_pEnd(nullptr)
	{

	}

	/*!
	* \brief The ObjList destructor.
	* Call the destructor of each ObjListCell within the ObjList.
	*/
	~ObjList()
	{
		ObjListCell<K> *l_cursor = nullptr;
		ObjListCell<K> *l_cursor_next = nullptr;
		l_cursor = m_pStart;

		m_pStart = nullptr;
		m_pEnd = nullptr;

		while(nullptr != l_cursor)
		{
			l_cursor_next = l_cursor->getNext();
			delete l_cursor;
			l_cursor = l_cursor_next;

			if(nullptr != l_cursor_next)
			{
				l_cursor_next = l_cursor_next->getNext();
			}
		}
	}

	/*!
	* \brief Add an object at the end of the ObjList
	* \param _pObj Pointer to the object to add.
	*/
	void addObject(K *_pObj)
	{
		ObjListCell<K> *l_cell = new ObjListCell<K>();

		if(nullptr != l_cell) // TODO raise error or proceed to assert here instead?
		{
			l_cell->setObj(_pObj);

			if(nullptr == m_pStart)
			{
				m_pStart = l_cell;
				m_pEnd = l_cell;
			}
			else
			{
				m_pEnd->setNext(l_cell);
				m_pEnd = m_pEnd->getNext();
			}
		}
	}

	/*!
	* \brief Return the object at the start of the list. This object is not removed, however.
	* \return Pointer to the object at the start of the list.
	*/
	K *getFirst()
	{
		if(nullptr != m_pStart)
		{
			return m_pStart->getObj();
		}
		else
		{
			return nullptr;
		}

	}

	/*!
	* \brief Return and remove the object at the start of the list.
	* \return Pointer to the object at the start of the list.
	*/
	K *removeFirst()
	{
		K *l_element = nullptr;

		if(nullptr != m_pStart)
		{
			ObjListCell<K> *l_cursor = m_pStart;
			l_element = l_cursor->getObj();

			if(m_pStart == m_pEnd)
			{
				m_pEnd = m_pStart->getNext(); // i.e. shall return nullptr.
			}

			m_pStart = m_pStart->getNext();

			delete l_cursor;
		}

		return l_element;
	}

	/*!
	* \brief Remove the object pointing at the same address of the object passed in parameter.
	* \return The removed object.
	*/
	K *removeObject(K *_pObj)
	{
		K *l_pObj = nullptr;
		ObjListCell<K> *l_cursor = m_pStart;
		ObjListCell<K> *l_cursor_prev = nullptr;

		while(nullptr != l_cursor)
		{
			if(_pObj == l_cursor->getObj())
			{
				l_pObj = l_cursor->getObj();

				if(nullptr != l_cursor_prev) // if l_cursor is not pointing the first element
				{
					l_cursor_prev->setNext(l_cursor->getNext());

					if(m_pEnd == l_cursor)
					{
						m_pEnd = l_cursor_prev;
					}
				}
				else
				{
					m_pStart = l_cursor->getNext();

					if(m_pEnd == l_cursor)
					{
						m_pEnd = m_pStart; // as only one element, shall be set to nullptr.
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

		return l_pObj;
	}

	/*!
	* \brief Return the ObjListCell at the start of the ObjList
	* \return Pointer to the ObjListCell at the start of the ObjList.
	*/
	ObjListCell<K> *getStart()
	{
		return m_pStart;
	}

private:
	/*!
	* \brief Pointer to the ObjListCell at the start of the ObjList.
	*/
	ObjListCell<K> *m_pStart;

	/*!
	* \brief Pointer to the ObjListCell at the end of the ObjList.
	*/
	ObjListCell<K> *m_pEnd;
};

/*!
* \brief Iterator for the ObjList.
* Separation of  iterator from ObjList allows multiple list-readers at the same time.
*/
template <class K> class ObjListIterator
{
public:
	/*!
	* \brief ObjListIterator constructor.
	* \param _pList Pointer to the ObjList.
	*/
	ObjListIterator(ObjList<K> *_pList)
	: m_pList(nullptr)
	, m_pCursor(nullptr)
	{
		m_pList = _pList;

		if(nullptr != m_pList)
		{
			m_pCursor = m_pList->getStart();
		}
	}

	/*!
	* \brief ObjListIterator destructor.
	*/
	~ObjListIterator()
	{
		// Do nothing.
	}

	/*!
	* \brief Return the current element pointed by the iterator and iterates to the next slot in the ObjList.
	* \return Pointer to the object carried, before this iteration.
	*/
	K *iterate()
	{
		K *l_pObj = nullptr;

		if(nullptr != m_pCursor)
		{
			l_pObj = m_pCursor->getObj();
			m_pCursor = m_pCursor->getNext();
		}

		return l_pObj;
	}

	/*!
	* \brief Return the current element pointed by the iterator.
	* \return Pointer to the current object carried by the ObjList, at this iteration.
	*/
	K *getCurrent()
	{
	    K *l_pRet = nullptr;

	    if(nullptr != m_pCursor)
	    {
            return m_pCursor->getObj();
        }

	    return l_pRet;
	}

private:
	/*!
	* \brief Pointer to the ObjList.
	*/
	ObjList<K> *m_pList;

	/*!
	* \brief Pointer to the current cell the iterator points to.
	*/
	ObjListCell<K> *m_pCursor;

};

#endif /* End _ENGINE_CONTAINERS_OBJLIST_H */
