/*
 * The <unnamed> factory builder project.
 *
 * \file test/engine/graph/BasicNodeEdgeNodeTest/BasicNodeEdgeNodeTest.h
 *
 * \brief Test for the bases of graphes.
 */

/*
 * CHANGELOG:
 * 15/12/2019: File creation (NG)
 */

#ifndef _TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_H
#define _TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_H

#include "TestableConcreteNode.h"
#include "TestableConcreteEdge.h"
#include <stdint.h>
#include <cxxtest/TestSuite.h>

class BasicNodeEdgeNodeTest : public CxxTest::TestSuite
{
public:
	BasicNodeEdgeNodeTest();

	~BasicNodeEdgeNodeTest();

	void testBasicNodeEdgeNode();
private:
	TestableConcreteNode *m_Source;
	TestableConcreteEdge *m_Edge;
	TestableConcreteNode *m_Sink;
};

#endif /* End _TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_H */
