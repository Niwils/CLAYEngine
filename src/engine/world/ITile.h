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
#include <Sprite.h>

class ITile
{
public:
	ITile();
	virtual ~ITile() = 0;

protected:
	Sprite *m_Sprite;

};
