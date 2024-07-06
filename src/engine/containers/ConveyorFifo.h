/*!
 * The <unnamed> factory builder project.
 *
 * \file src/engine/containers/ConveyorFifo.h
 *
 * \brief A FIFO container, with manual stepping.
 */

/*
 * CHANGELOG:
 * 30/11/2019: File creation (NG)
 */

#ifndef _ENGINE_CONTAINERS_CONVEYORFIFO_H
#define _ENGINE_CONTAINERS_CONVEYORFIFO_H

#include <Types.h>

/*!
* \brief This is a FIFO class used by the conveyors.
* This FIFO does not provide a new item at its input to be directly at its output. It has to be stepped by the number of slots before being propagated to the output.
*/
template <class K> class ConveyorFifo
{
public:
	/*!
	* \brief The FIFO class constructor.
	* \param _fifoSize the FIFO size
	*/
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

	/*!
	* \brief The FIFO class destructor
	* \todo Destroy the FIFO content?
	*/
	~ConveyorFifo()
	{
		delete m_Fifo;
	}

	/*!
	* \brief Return the FIFO size
	* \return The total number of slots in the FIFO.
	*/
	s_EdgeFifoSize getFifoSize()
	{
		return m_FifoSize;
	}

	/*!
	* \brief Request the FIFO to move all its elements to the next slot, if possible.
	* If the output slot is not empty, nothing will happen.
	*/
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

	/*!
	* \brief Return the element at the output of the FIFO
	* \return The element at the FIFO output. Can be nullptr if no element is propagated at the output.
	*/
	K* getFirstElement()
    {
	    return m_Fifo[(m_FifoSize-1)];
    }

	/*!
	* \brief Return the element at a given index. 0 being at the input, FIFO_SIZE-1 at the output.
	* \param _elementNo The element index within the FIFO.
	* \return The element at the FIFO index. Can be nullptr if no element is there.
	*/
    K* getElementNo(s_EdgeFifoSize _elementNo)
    {
	    // TODO: assert _elementNo < m_FifoSize
	    return m_Fifo[_elementNo];
    }

	/*!
	* \brief Move a given element at the next slot, if possible.
	* \param _elementNo The element index within the FIFO.
	* \return True if the move has been performed, false otherwise.
	*/
    bool moveToNextSlot(s_EdgeFifoSize _elementNo)
    {
        // TODO: assert _elementNo < m_FifoSize-1

        if(nullptr == m_Fifo[_elementNo+1])
        {
            m_Fifo[_elementNo+1] = m_Fifo[_elementNo];
            m_Fifo[_elementNo] = nullptr;
            return true;
        }

        return false;
    }

	/*!
	* \brief Unqueue the element at the FIFO output. Can be nullptr if no element is available.
	* \return The element at the FIFO output, if available.
	*/
	K* unqueue()
	{
		K *l_ret = nullptr;

		l_ret = m_Fifo[(m_FifoSize-1)];

		m_Fifo[(m_FifoSize-1)] = nullptr;

		return l_ret;
	}

	/*!
	* \brief Returns if the FIFO input has an element or not.
	* \return True if the FIFO input is busy, false otherwise.
	*/
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

	/*!
	* \brief Queues a new object within the FIFO.
	* \todo add to error codes to queue().
	* \param _obj The new object to queue.
	*/
	void queue(K *_obj)
	{
		if(nullptr == m_Fifo[0])
		{
			m_Fifo[0] = _obj;
		}
	}

	/*!
	* \brief Clears the FIFO content.
	* Warning, clearing does not delete the content of the FIFO.
	*/
	void clear()
	{
		for(s_EdgeFifoSize icpt; m_FifoSize > icpt; icpt++)
		{
			m_Fifo[icpt] = nullptr;
		}
	}

private:
	/*!
	* \brief The FIFO size.
	*/
	s_EdgeFifoSize m_FifoSize;

	/*!
	* \brief The FIFO elements array.
	*/
	K **m_Fifo;
};

#endif /* End _ENGINE_CONTAINERS_CONVEYORFIFO_H */
