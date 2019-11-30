/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IGameEvent.h
 *
 * \brief A list container.
 */

/*
 * CHANGELOG:
 * 30/11/2019: File creation (NG)
 */

template <class K> class ObjList
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

	ObjList *getNext()
	{
		return m_Next;
	}

	void setNext(ObjList *_next)
	{
		m_Next = _next;
	}

private:
	K *m_Obj;
	ObjList *m_Next;
};
