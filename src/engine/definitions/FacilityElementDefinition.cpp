/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/definitions/FacilityElementDefinition.h
 *
 * \brief A FacilityElementDefinition is a wall, a basic factory floor tile, and so on.
 */

/*
 * CHANGELOG:
 * 27/04/2024: File creation (NG)
 */

#include <FacilityElementDefinition.h>

FacilityElementDefinition::FacilityElementDefinition(s_gameElementUUID _uuid, ISprite *_sprite, s_bool _isAnimated,
								s_bool _isPlayerEditable)
: IDisplayableGameDefinition(_uuid, _sprite, _isAnimated,_isPlayerEditable)
{
	
}

FacilityElementDefinition::~FacilityElementDefinition()
{

}