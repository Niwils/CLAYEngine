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

class IGraphElement
{
public:
	IGraphElement();

	virtual ~IGraphElement() = 0;
};

#endif /* End _ENGINE_GRAPH_IGRAPHELEMENT_H */
