/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/transportation/PickupArea.h
 *
 * \brief A PickupArea object is an object carrying a limited amount of ItemContainer.
 * It is a source for a transportation graph between two distinct production lines (item building a new item)
 * or a delivery area to a production line (material to item).
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */
#ifndef _ENGINE_TRANSPORTATION_PICKUPAREA_H
#define _ENGINE_TRANSPORTATION_PICKUPAREA_H

#include <INode.h>
#include <ItemContainer.h>

class PickupArea : public INode
{
public:
	PickupArea(s_ItemContainerQty _maxQtyContainers);
	~PickupArea();

	bool addItemToContainer(Item *_item);

	void runTick();

private:
	ObjList<ItemContainer> *mt_Containers;
    s_ItemContainerQty m_nbContainersMax;
    s_ItemContainerQty m_nbCurrentContainers;
};

#endif /* End _ENGINE_TRANSPORTATION_PICKUPAREA_H */
