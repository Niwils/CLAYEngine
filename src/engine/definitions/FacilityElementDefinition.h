/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/definitions/FacilityElementDefinition.h
 *
 * \brief A FacilityElementDefinition is a wall, a basic factory floor tile, and so on.
 */

/*
 * CHANGELOG:
 * 14/04/2024: File creation (NG)
 */

#ifndef _ENGINE_DEFINITIONS_FACILITYELEMENTDEFINITION_H_
#define _ENGINE_DEFINITIONS_FACILITYELEMENTDEFINITION_H_

#include <IDisplayableGameDefinition.h>
#include <ISprite.h>

class FacilityElementDefinition : public IDisplayableGameDefinition
{
	FacilityElementDefinition(s_gameElementUUID _uuid, ISprite *_sprite, s_bool _isAnimated,
								s_bool _isPlayerEditable);

	~FacilityElementDefinition();

	s_bool isPLayerEditable();

private:
	s_bool m_isAnimated;  		/*!< If true, indicates the sprite is animated. */
	s_bool m_IsPlayerEditable;  /*!< If true, the player can edit or change the game element for another. */

};


#endif /* End of _ENGINE_DEFINITIONS_FACILITYELEMENTDEFINITION_H_ */
