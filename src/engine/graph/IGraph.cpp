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

#include <IGraph.h>

IGraph::IGraph()
{
	m_nodes = new HashHeap<s_GraphElementUUID, INode *>();
	m_edges = new HashHeap<s_GraphElementUUID, IEdge *>();
}

IGraph::~IGraph()
{

}

void IGraph::addEdge(IEdge *_edge)
{
	m_edges->addObj(_edge->getUUID(), _edge);
}

void IGraph::addNode(INode *_node)
{
	m_nodes->addObj(_node->getUUID(), _node);
}