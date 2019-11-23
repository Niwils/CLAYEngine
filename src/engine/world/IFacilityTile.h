/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/world/IFacilityTile.h
 *
 * \brief An abstract tile of the World 2D map which is into the factory facility.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */
#include <ITile.h>

class IFacilityTile : public ITile
{
public:
	IFacilityTile();
	virtual ~IFacilityTile() = 0;

};
