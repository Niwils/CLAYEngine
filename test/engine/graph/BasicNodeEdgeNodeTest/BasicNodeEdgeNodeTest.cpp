/*
 * The <unnamed> factory builder project.
 *
 * \file test/containers/ObjList/ObjListTest.h
 *
 * \brief Implementation of the test for the ObjList container
 */

/*
 * CHANGELOG:
 * 02/12/2019: File creation (NG)
 */

#include "BasicNodeEdgeNodeTest.h"

BasicNodeEdgeNodeTest::BasicNodeEdgeNodeTest()
: CxxTest::TestSuite()
{
	m_Source = new TestableConcreteNode();
	m_Edge = new TestableConcreteEdge(4U);
	m_Sink = new TestableConcreteNode();
}

BasicNodeEdgeNodeTest::~BasicNodeEdgeNodeTest()
{
	delete m_Source;
	delete m_Edge;
	delete m_Sink;
}

void BasicNodeEdgeNodeTest::testBasicNodeEdgeNode()
{
	m_Source->addOutput(m_Edge);
	m_Edge->setSource(m_Source);
	m_Edge->setSink(m_Sink);
	m_Sink->setInput(m_Edge);

	ObjList<IGraphElement> *l_srcOuts = m_Source->getOutputs();

	IGraphElement *l_in = l_srcOuts->iterate();

	TS_ASSERT_EQUALS(l_in, m_Edge);

	IGraphElement *l_out = m_Edge->getSink();

	TS_ASSERT_EQUALS(l_out, m_Sink);

}
