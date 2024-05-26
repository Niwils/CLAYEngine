/*
 * The <unnamed> factory builder project.
 *
 * \file /src/engine/definitions/WorldElementDefinition.h
 *
 * \brief This is the class defining a given non-playable surface in the game.
 * 		  Such surface can be a tree, a road at the outside of the factory, and so on.
 */

/*
 * CHANGELOG:
 * 14/04/2024: File creation (NG)
 */

#ifndef _ENGINE_DEFINITIONS_WORLDELEMENTDEFINITION_H_
#define _ENGINE_DEFINITIONS_WORLDELEMENTDEFINITION_H_


#include <IDisplayableGameDefinition.h>
#include <ISprite.h>
#include <Types.h>

/*! \class WorldElementDefinition
 *
 *
 */
class WorldElementDefinition : public IDisplayableGameDefinition
{
public:
	/*! The World Element definition constructor.
	*/
	WorldElementDefinition(s_gameElementUUID _uuid, ISprite *_sprite, s_bool _isAnimated);

	~WorldElementDefinition();

private:
};


#endif /* End of _ENGINE_DEFINITIONS_WORLDELEMENTDEFINITION_H_ */
