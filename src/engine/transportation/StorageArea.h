/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/transportation/StorageArea.h
 *
 * \brief A StorageArea object is a sink in the transportation graph.
 *	It is connected to an ItemFactory interface. When this latter requires an Item, this object
 *	unloads it from the ContainerCarrier and passes it to the interface.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _ENGINE_TRANSPORTATION_STORAGEAREA_H
#define _ENGINE_TRANSPORTATION_STORAGEAREA_H

#include <Types.h>
#include <INode.h>
//#include <IFacilityTile.h>
#include <ObjList.h>
#include <ItemContainer.h>
#include <Transporter.h>

class StorageArea : public INode //, IFacilityTile
{
public:
	StorageArea(s_GraphElementUUID _uuid);
	~StorageArea();

	void deliverContainer(ItemContainer *_container);

	ItemContainer *loadEmptyContainer();

	Item *pickRawMaterial(s_ItemTypeUUID _itemType);

	bool checkAvailability(s_ItemTypeUUID _itemType);

	bool checkAndPickItem(s_ItemTypeUUID _itemType, Item *_pickedItem);

	void lockAccess();

	void unlockAccess();

	IToken *getToken();

private:
	// TODO make a better computation-optimized container system.
	ObjList<ItemContainer> *m_ActiveContainers;
	ObjList<ItemContainer> *m_EmptyContainers;
	// TODO add max of ItemContainer
	// TODO add pointer to the ItemFactoryInterface
};

#endif /* End _ENGINE_TRANSPORTATION_STORAGEAREA_H */
