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

#include <HashHeap.h>
#include <stdint.h>
#include <cxxtest/TestSuite.h>

class BasicHashMapTest : public CxxTest::TestSuite
{
public:
	BasicHashMapTest();

	~BasicHashMapTest();

	void testBasicHashMapTest();
private:
	HashHeap<s_HashHeapDepth, s_HashHeapDepth *> *m_theHashMap;
};

#endif /* End _TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_H */
