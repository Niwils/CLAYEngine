//
// Created by Niels Grataloup on 20/12/2020.
//

#ifndef FACTORYBUILDER_ITRANSPORTATIONNODE_H
#define FACTORYBUILDER_ITRANSPORTATIONNODE_H

#include <HashHeap.h>
#include <INode.h>
#include <GraphCourse.h>

class ITransportationNode : public INode
{
public:
	ITransportationNode(s_GraphElementUUID _uuid);
	virtual ~ITransportationNode() = 0;

	virtual IToken *getToken(s_GraphElementUUID _caller_uuid) = 0;

private:
	HashHeap<s_GraphElementUUID, GraphCourse *> *m_reachableNodesCourses;
};


#endif //FACTORYBUILDER_ITRANSPORTATIONNODE_H
