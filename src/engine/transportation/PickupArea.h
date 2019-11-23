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
#include <INode.h>
#include <IFacilityTile.h>

class PickupArea : public INode, IFacilityTile
{
public:
	PickupArea();
	~PickupArea();

private:
	// TODO add list of ItemContainer
	// TODO add max of ItemContainer
};
