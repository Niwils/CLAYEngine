/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/transportation/ItemContainer.h
 *
 * \brief An ItemContainer carries a limited set of Item objects. It can be awaiting a complete load
 * or to be transported to a StorageArea.
 *
 * This is an element proper to transportation:
 * - if empty:
 * -- if no PickupArea is available, it shall be stored in a "waiting" area
 * -- if a PickupArea is available, it shall be transported to the first requesting PickupArea
 *
 * - if full:
 * -- if a StorageArea with an available slot requires the associated Item type this object carries,
 * 		it shall be carried to it.
 * -- otherwise, it shall be stored in a "waiting" area.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */
#ifndef _ENGINE_TRANSPORTATION_ITEMCONTAINER_H
#define _ENGINE_TRANSPORTATION_ITEMCONTAINER_H

#include <Item.h>

class ItemContainer
{
public:
	ItemContainer(s_ItemTypeUUID _itemType, s_ItemQuantity _max_qty);
	~ItemContainer();

	s_ItemTypeUUID getCarriedItemType();

	void addItem(Item *_item);
	Item *pickItem();

	bool isEmpty();

	bool isFull();

private:
	ObjList<Item> m_CarriedItems;
	s_ItemTypeUUID m_CarriedItemType;
	s_ItemQuantity m_MaxQty;
	s_ItemQuantity m_CurrentQty;
};

#endif /* End _ENGINE_TRANSPORTATION_ITEMCONTAINER_H */
