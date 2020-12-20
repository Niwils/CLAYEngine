/*
 * The <unnamed> factory builder project.
 *
 * \file test/engine/transportation/BasicConveyorAndCarrier/BasicConveyorAndCarrier.h
 *
 * \brief Test for the bases of PickupArea, ItemCarrier with multiple Items, and StorageArea.
 */

/*
 * CHANGELOG:
 * 08/12/2020: File creation (NG)
 */

#ifndef _TEST_ENGINE_TRANSPORTATION_BASICCONVEYORANDCARRIER_H
#define _TEST_ENGINE_TRANSPORTATION_BASICCONVEYORANDCARRIER_H

#include <PickupArea.h>
#include <StorageArea.h>
#include <Item.h>
#include <ItemContainer.h>
#include <TransportationTile.h>
#include <Transporter.h>
#include <stdint.h>
#include <cxxtest/TestSuite.h>

class BasicConveyorAndCarrier : public CxxTest::TestSuite
{
public:
	BasicConveyorAndCarrier();

	~BasicConveyorAndCarrier();

	void testBasicConveyorAndCarrier();
private:
	Item *m_Item;
    ItemContainer *m_ItemCase;
	StorageArea *m_Sink;
	TransportationTile *m_tile;
	PickupArea *m_Source;

	Transporter *m_carrier;

	const TransporterDefinition c_carrierDef =
    {
     1U,
     1U,
     1U
    };
};

#endif /* End _TEST_ENGINE_TRANSPORTATION_BASICCONVEYORANDCARRIER_H */
