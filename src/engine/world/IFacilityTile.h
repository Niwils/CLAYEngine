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
#ifndef _ENGINE_WORLD_IFACILITYTILE_H
#define _ENGINE_WORLD_IFACILITYTILE_H

#include <ITile.h>
#include <GeographyDefinitions.h>


class IFacilityTile : public ITile
{
public:
	IFacilityTile();
	virtual ~IFacilityTile() = 0;


	IFacilityTile *getNeighbourTile(eGeographyDefinition _neighbour_position);
	void setNeighbourTile(IFacilityTile *_neighbour, eGeographyDefinition _neighbour_position);

protected:
	IFacilityTile *m_NeighbourTiles[eGeographyDefinition_Max];

};

#endif /* End _ENGINE_WORLD_IFACILITYTILE_H */
