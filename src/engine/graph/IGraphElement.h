/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/graph/IGraphElement.h
 *
 * \brief An IGraphElement object is an abstract element of a graph.
 */

/*
 * CHANGELOG:
 * 15/12/2019: File creation (NG)
 */

#ifndef _ENGINE_GRAPH_IGRAPHELEMENT_H
#define _ENGINE_GRAPH_IGRAPHELEMENT_H
#include <IToken.h>
#include <Types.h>

class IGraphElement
{
public:
	IGraphElement(s_GraphElementUUID _uuid);

	virtual ~IGraphElement() = 0;

	virtual IToken *getToken() = 0;

	s_GraphElementUUID getUUID();

protected:
    s_GraphElementUUID m_uuid;
};

#endif /* End _ENGINE_GRAPH_IGRAPHELEMENT_H */
