/*
 * The <unnamed> factory builder project.
 *
 * \file /test/engine/graph/BasicNodeEdgeNodeTest/TestableConcreteEdge.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 15/12/2019: File creation (niels)
 */

#ifndef TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_TESTABLECONCRETEEDGE_H_
#define TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_TESTABLECONCRETEEDGE_H_

#include <IEdge.h>

class TestableConcreteEdge : public IEdge
{
public:
	TestableConcreteEdge(s_GraphElementUUID _uuid, s_EdgeFifoSize _size);
	~TestableConcreteEdge();
};



#endif /* End TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_TESTABLECONCRETEEDGE_H_ */
