/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/world/ITile.h
 *
 * \brief An abstract tile of the World 2D map.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _ENGINE_WORLD_ITILE_H
#define _ENGINE_WORLD_ITILE_H

// #include <Sprite.h>
#include <ISpriteWindow.h>

class ITile
{
public:
	ITile();
	virtual ~ITile() = 0;

	ISpriteWindow *getSpriteWindow();

protected:
	// Attributes setting the FOV over the complete sprite
	ISpriteWindow *m_pSpriteWindow;

	// Attributes used when animating the sprite
	s_nbFrames m_currentFrame;

};

#endif /* End _ENGINE_WORLD_ITILE_H */
