/**
 * The CLAYEngine project.
 *
 * \file /src/game/transportation/PickupArea.h
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

#include <ITransportationNode.h>
#include <ItemContainer.h>
#include <Item.h>

class PickupArea : public ITransportationNode
{
public:
    /**
     * @brief The PickupArea constructor
     * @param _uuid The IGraphElement UUID (generated by the GraphElementFactory)
     */
	PickupArea(s_GraphElementUUID _uuid, s_ItemContainerQty _maxQtyContainers);
	~PickupArea();

	void addContainer(ItemContainer *_container);
	bool addItemToContainer(Item *_item);

    /**
     * Request a Transporter. This function overrides the INode one, as it ensures the Transporter is ready to be released.
     * @return A Transporter, if one is ready to be released. Nullptr otherwise.
     */
	IToken *getToken(s_GraphElementUUID _uuid);

private:
	ObjList<ItemContainer> *mt_Containers; ///< List of currently hold containers
    s_ItemContainerQty m_nbContainersMax; ///< Maximum number of containers the area can contain.
    s_ItemContainerQty m_nbCurrentContainers; ///< Current number of contained containers in the area.
};

#endif /* End _ENGINE_TRANSPORTATION_PICKUPAREA_H */
