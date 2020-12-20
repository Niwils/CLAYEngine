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

#include "BasicConveyorAndCarrier.h"

BasicConveyorAndCarrier::BasicConveyorAndCarrier()
: CxxTest::TestSuite()
{
	m_Source = new PickupArea(0U, 1U);
	m_Item = new Item(0U, nullptr);
	m_ItemCase = new ItemContainer(0U, 1U);
	m_Sink = new StorageArea(1U);
	m_tile = new TransportationTile(2U, 2U);

	m_carrier = new Transporter(1U, c_carrierDef);
}

BasicConveyorAndCarrier::~BasicConveyorAndCarrier()
{
	delete m_Source;
	delete m_carrier;
	delete m_Item;
	delete m_ItemCase;
	delete m_Sink;

	delete m_tile;
}

void BasicConveyorAndCarrier::testBasicConveyorAndCarrier()
{
	m_Source->addOutput(m_tile);
	m_tile->setSource(m_Source);
	m_tile->setSink(m_Sink);
	m_Sink->setInput(m_tile);

	m_Source->setToken(m_carrier);

    m_Source->addContainer(m_ItemCase);

    bool l_itemIsCarried = m_Source->addItemToContainer(m_Item);

	TS_ASSERT_EQUALS(true, l_itemIsCarried);

	Transporter *l_Token = nullptr;
	for(int icpt = 0U; 10U > icpt; icpt++)
	{
        l_Token = dynamic_cast<Transporter *>(m_Sink->getToken());
        m_carrier->runTick();
    }

	TS_ASSERT_EQUALS(true, l_Token->isEmpty())
}
