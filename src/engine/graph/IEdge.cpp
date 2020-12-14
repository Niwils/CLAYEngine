/*
 * The <unnamed> factory builder project.
 *
 * \file /src/engine/graph/IEdge.cpp
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 15/12/2019: File creation (NG)
 */

#include <IEdge.h>

IEdge::IEdge(s_EdgeFifoSize _size)
: IGraphElement()
, m_FifoSize(_size)
, m_Source(nullptr)
, m_Sink(nullptr)
, m_Fifo(nullptr)
{
	m_Fifo = new ConveyorFifo<IToken>(m_FifoSize);
}

IEdge::~IEdge()
{
	m_Fifo->clear();

	delete m_Fifo;
}

void IEdge::setSource(IGraphElement *_source)
{
	m_Source = _source;
}

IGraphElement *IEdge::getSource()
{
	return m_Source;
}

void IEdge::setSink(IGraphElement *_source)
{
	m_Sink = _source;
}

IGraphElement *IEdge::getSink()
{
	return m_Sink;
}

void IEdge::stepFifo()
{
	m_Fifo->stepFifo();
}

// TODO manage errors for queue()
void IEdge::queue(IToken *_token)
{
	m_Fifo->queue(_token);
}

// TODO manage errors for unqueue()?
IToken *IEdge::unqueue()
{
	IToken *l_ret = nullptr;

	l_ret = m_Fifo->unqueue();

	return l_ret;
}

ConveyorFifo<IToken> *IEdge::getFifo()
{
	return m_Fifo;
}

IToken *IEdge::getToken()
{
    return this->unqueue();
}
