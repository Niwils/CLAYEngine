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

#ifndef _TEST_ENGINE_PRODUCTION_BASICPRODUCTIONTEST_H
#define _TEST_ENGINE_PRODUCTION_BASICPRODUCTIONTEST_H

#include <Conveyor.h>
#include <ItemProcessor.h>
#include <Item.h>
#include <stdint.h>
#include <cxxtest/TestSuite.h>

class BasicProductionTest : public CxxTest::TestSuite
{
public:
	BasicProductionTest();

	~BasicProductionTest();

	void testBasicProductionTest();
private:
	ItemProcessor *m_Source;
	Conveyor *m_Conveyor;
	ItemProcessor *m_Sink;
};

#endif /* End _TEST_ENGINE_PRODUCTION_BASICPRODUCTIONTEST_H */
