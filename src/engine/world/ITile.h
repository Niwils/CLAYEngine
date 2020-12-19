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

#include <Sprite.h>

class ITile
{
public:
	ITile();
	virtual ~ITile() = 0;

protected:
	Sprite *m_Sprite;

	

};

#endif /* End _ENGINE_WORLD_ITILE_H */
