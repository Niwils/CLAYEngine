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

class ItemContainer
{
public:
	ItemContainer();
	~ItemContainer();

private:
	// TODO add list of carried Item
	// TODO add type of supported Item
	// TODO add maximum number of Item
	// TODO add current number of Item
};

#endif /* End _ENGINE_TRANSPORTATION_ITEMCONTAINER_H */
