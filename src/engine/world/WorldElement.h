/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/world/World.h
 *
 * \brief The map the game is currently evolving (i.e. what the player can see)
 * It is a 2D map of ITile objects, which can be a facility floor or pure decoration.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _ENGINE_WORLD_WORLD_H
#define _ENGINE_WORLD_WORLD_H
#include <ITile.h>
#include <WorldElementDefinition.h>
#include <SpriteWindow.h>
#include <IRenderer.h>

class WorldElement : public ITile
{
public:
	WorldElement(WorldElementDefinition *_def, IRenderer *_pRenderer);
	~WorldElement();

private:
	WorldElementDefinition *m_pDef;
};

#endif /* End _ENGINE_WORLD_WORLD_H */
