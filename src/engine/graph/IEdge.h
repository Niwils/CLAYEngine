/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/graph/IEdge.h
 *
 * \brief An IEdge object a n-step FIFO allowing ITokens objects to transit
 * 			between two INode objects. An IEdge can be seen as a conveyor belt,
 * 			or any transportation system.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _ENGINE_GRAPH_IEDGE_H
#define _ENGINE_GRAPH_IEDGE_H

#include <Types.h>
#include <IToken.h>
#include <IGraphElement.h>
#include <ConveyorFifo.h>

class IEdge : public IGraphElement
{
public:

	IEdge(s_EdgeFifoSize _size);

	virtual ~IEdge() = 0;

	void setSource(IGraphElement *_source);

	IGraphElement *getSource();

	void setSink(IGraphElement *_source);

	IGraphElement *getSink();

	void stepFifo();

	// TODO manage errors for queue()
	void queue(IToken *_token);

	// TODO manage errors for unqueue()?
	IToken *unqueue();

protected:
	ConveyorFifo<IToken> *getFifo();

private:

	s_EdgeFifoSize m_FifoSize;
	IGraphElement *m_Source;
	IGraphElement *m_Sink;

	ConveyorFifo<IToken> *m_Fifo;

};

#endif /* _ENGINE_GRAPH_IEDGE_H */
