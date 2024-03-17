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
}

BasicNodeEdgeNodeTest::~BasicNodeEdgeNodeTest()
{
}

void BasicNodeEdgeNodeTest::testBasicNodeEdgeNode()
{
	m_Source = new TestableConcreteNode(0U);
	m_Edge = new TestableConcreteEdge(1U, 4U);
	m_Sink = new TestableConcreteNode(3U);
	TS_TRACE("Starting node edge node basic test (only one source, one edge, one sink).");

	TS_TRACE("Building the graph");
	m_Source->addOutput(m_Edge);
	m_Edge->setSource(m_Source);
	m_Edge->setSink(m_Sink);
	m_Sink->setInput(m_Edge);

	TS_TRACE("Getting the source node edge array");
	ObjList<IGraphElement> *l_srcOuts = m_Source->getOutputs();

	ObjListIterator<IGraphElement> *l_iterator = new ObjListIterator<IGraphElement>(l_srcOuts);

	IGraphElement *l_edge = l_iterator->iterate();

	TS_TRACE("Checking the first edge from the source node is the only one edge of the graph");
	TS_ASSERT_EQUALS(l_edge, m_Edge);

	l_edge = l_iterator->iterate();

	TS_TRACE("Checking no more than one edge is present");
	TS_ASSERT_EQUALS(l_edge, nullptr);

	TS_TRACE("Checking the edge sink is the only sink node of the graph");
	IGraphElement *l_out = m_Edge->getSink();

	TS_ASSERT_EQUALS(l_out, m_Sink);

	delete l_iterator;

	delete m_Source;
	delete m_Edge;
	delete m_Sink;
}

void BasicNodeEdgeNodeTest::testTwoEdgesOneSinkNode()
{
	m_Source = new TestableConcreteNode(0U);
	m_Edge = new TestableConcreteEdge(1U, 4U);
	m_SecondEdge = new TestableConcreteEdge(2U, 1U);
	m_Sink = new TestableConcreteNode(3U);
	TS_TRACE("Starting a one-source two-edges one-sink graph.");

	TS_TRACE("Building the graph");
	m_Source->addOutput(m_Edge);
	m_Source->addOutput(m_SecondEdge);
	m_Edge->setSource(m_Source);
	m_Edge->setSink(m_Sink);

	m_SecondEdge->setSource(m_Source);
	m_SecondEdge->setSink(m_Sink);

	m_Sink->setInput(m_Edge);

	TS_TRACE("Getting the source node edge array");
	ObjList<IGraphElement> *l_srcOuts = m_Source->getOutputs();

	ObjListIterator<IGraphElement> *l_iterator = new ObjListIterator<IGraphElement>(l_srcOuts);

	IGraphElement *l_edge = l_iterator->iterate();

	TS_TRACE("Checking the first edge from the source node is the only one edge of the graph");
	TS_ASSERT_EQUALS(l_edge, m_Edge);
	TS_ASSERT_EQUALS(l_edge->getUUID(), 1);


	l_edge = l_iterator->iterate();

	TS_ASSERT_EQUALS(l_edge, m_SecondEdge);
	TS_ASSERT_EQUALS(l_edge->getUUID(), 2);

	l_edge = l_iterator->iterate();

	TS_TRACE("Checking no more than one edge is present");
	TS_ASSERT_EQUALS(l_edge, nullptr);

	TS_TRACE("Checking the edges sinks are the only and same sink node of the graph");
	IGraphElement *l_out = m_Edge->getSink();

	TS_ASSERT_EQUALS(l_out, m_Sink);

	IGraphElement *l_secondOut = m_SecondEdge->getSink();
	TS_ASSERT_EQUALS(l_secondOut, m_Sink);

	delete l_iterator;

	delete m_Source;
	delete m_Edge;
	delete m_SecondEdge;
	delete m_Sink;
}
