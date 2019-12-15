/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/containers/ConveyorFifo.h
 *
 * \brief A list container.
 */

/*
 * CHANGELOG:
 * 30/11/2019: File creation (NG)
 */

#ifndef _ENGINE_CONTAINERS_CONVEYORFIFO_H
#define _ENGINE_CONTAINERS_CONVEYORFIFO_H

#include <Types.h>

template <class K> class ConveyorFifo
{
public:
	ConveyorFifo(s_EdgeFifoSize _fifoSize)
	: m_FifoSize(_fifoSize)
	, m_Fifo(nullptr)
	{
		m_Fifo = new K*[m_FifoSize];

		for(int icpt = 0; m_FifoSize > icpt; icpt++)
		{
			m_Fifo[icpt] = nullptr;
		}
	}

	~ConveyorFifo()
	{
		delete m_Fifo;
	}

	s_EdgeFifoSize getFifoSize()
	{
		return m_FifoSize;
	}

	void stepFifo()
	{
		if(nullptr == m_Fifo[(m_FifoSize-1)])
		{
			for(int icpt = (m_FifoSize-1); 0 < icpt; icpt--)
			{
				m_Fifo[icpt] = m_Fifo[icpt-1];
			}
		}

		m_Fifo[0] = nullptr;
	}

	K* unqueue()
	{
		K *l_ret = nullptr;

		l_ret = m_Fifo[(m_FifoSize-1)];

		m_Fifo[(m_FifoSize-1)] = nullptr;

		return l_ret;
	}

	bool isFifoFull()
	{
		if(nullptr == m_Fifo[0])
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// TODO add to error codes to queue()
	void queue(K *_obj)
	{
		if(nullptr == m_Fifo[0])
		{
			m_Fifo[0] = _obj;
		}
	}

private:
	s_EdgeFifoSize m_FifoSize;

	K **m_Fifo;
};

#endif /* End _ENGINE_CONTAINERS_CONVEYORFIFO_H */
