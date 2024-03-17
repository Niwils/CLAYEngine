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

#include "BasicTransportationGraph.h"

BasicTransportationGraph::BasicTransportationGraph()
: CxxTest::TestSuite()
{
	m_Source = new PickupArea(0U, 1U);
	m_Item = new Item(0U, nullptr);
	m_ItemCase = new ItemContainer(0U, 1U);
	m_Sink = new StorageArea(2U);
	m_tile = new TransportationTile(1U, 2U);

	m_carrier = new Transporter(1U, c_carrierDef);
}

BasicTransportationGraph::~BasicTransportationGraph()
{
	delete m_Source;
	delete m_carrier;
	delete m_Item;
	delete m_ItemCase;
	delete m_Sink;

	delete m_tile;
}

void BasicTransportationGraph::testBasicTransportationGraph()
{
	m_Source->addOutput(m_tile);
	m_tile->setSource(m_Source);
	m_tile->setSink(m_Sink);
	m_Sink->setInput(m_tile);

	m_Source->setToken(m_carrier);

    m_Source->addContainer(m_ItemCase);

    bool l_itemIsCarried = m_Source->addItemToContainer(m_Item);

    ObjList<s_GraphElementUUID> *l_tokenPath = new ObjList<s_GraphElementUUID>();

    for (int icpt = 0; 3U >= icpt; icpt++)
	{
    	s_GraphElementUUID *l_uuid = new s_GraphElementUUID(icpt);
    	l_tokenPath->addObject(l_uuid);
	}

    GraphCourse *l_tokenCourse = new GraphCourse(0U, 3U);
    l_tokenCourse->setPath(l_tokenPath);
    l_tokenCourse->registerSubscriber(m_carrier);
    m_carrier->setGraphCourse(l_tokenCourse);
    m_carrier->setCurrentGraphElementID(0U);

	TS_ASSERT_EQUALS(true, l_itemIsCarried);

	Transporter *l_Token = nullptr;
	for(int icpt = 0U; 10U > icpt; icpt++)
	{
        l_Token = dynamic_cast<Transporter *>(m_Sink->getToken(3U));
        m_carrier->runTick();
    }

	TS_ASSERT_EQUALS(true, l_Token->isEmpty())

	delete l_tokenCourse;
	delete l_tokenPath;
}
