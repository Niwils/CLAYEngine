/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/definitions/WorldElementDefinition.h
 *
 * \brief A FacilityElementDefinition is a wall, a basic factory floor tile, and so on.
 */

/*
 * CHANGELOG:
 * 27/04/2024: File creation (NG)
 */

#include <WorldElementDefinition.h>

WorldElementDefinition::WorldElementDefinition(s_gameElementUUID _uuid, ISprite *_sprite, s_bool _isAnimated)
: IDisplayableGameDefinition(_uuid, _sprite, _isAnimated, false)
{
	
}

WorldElementDefinition::~WorldElementDefinition()
{

}