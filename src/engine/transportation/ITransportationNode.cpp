//
// Created by Niels Grataloup on 20/12/2020.
//

#include <ITransportationNode.h>

ITransportationNode::ITransportationNode(s_GraphElementUUID _uuid)
: INode(_uuid)
{
	m_reachableNodesCourses = new HashHeap<s_GraphElementUUID, GraphCourse *>();
}

ITransportationNode::~ITransportationNode()
{
	delete m_reachableNodesCourses;
}
