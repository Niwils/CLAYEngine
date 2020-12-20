/**
 * The CLAYEngine project.
 *
 * @file /src/engine/graph/IGraph.h
 *
 * @brief An IGraph contains the first edge introduced in a Graph
 */

/*
 * CHANGELOG:
 * 20/12/2020: File creation (NG)
 */

#ifndef FACTORYBUILDER_IGRAPH_H
#define FACTORYBUILDER_IGRAPH_H

#include <INode.h>
#include <IEdge.h>
#include <HashHeap.h>

class IGraph
{
public:
	IGraph();
	virtual ~IGraph() = 0;

	void addNode(INode *_node);

	void addEdge(IEdge *_edge);

protected:
	HashHeap<s_GraphElementUUID, INode *> *m_nodes;
	HashHeap<s_GraphElementUUID, IEdge *> *m_edges;
};

#endif