/*
 * The <unnamed> factory builder project.
 *
 * \file src/osal/common/rendering/ISprite.h
 *
 * \brief A sprite container for visual renderer.
 * 		(No architecture yet defined).
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */

#ifndef _ENGINE_OSAL_COMMON_RENDERING_ISPRITE_H
#define _ENGINE_OSAL_COMMON_RENDERING_ISPRITE_H

#include <Types.h>

class ISprite
{
public:
	ISprite(s_nbPixels _height, s_nbPixels _width, s_nbPixels _length, s_nbFrames _nbFrames, s_coord2d _center);
	~ISprite();

	s_coord2d getFrameCenter();
	s_nbPixels getHeight();
	s_nbPixels getWidth();
	s_nbPixels getLength();

	s_nbFrames getNbFrames();

protected:
	s_coord2d m_spriteFrameCenter; /*!< This attribute is used to allow the system to know where is the
								pixel representing the center/origin for positioning purposes. */
	// TODO: do a better description of m_spriteDisplayCoord vs the PlayerCamera on the Wiki.
	s_nbPixels m_height;
	s_nbPixels m_width; // TODO: is this useful?
	s_nbPixels m_length;
	s_nbFrames m_nbFrames;


};

#endif /* End _ENGINE_OSAL_COMMON_RENDERING_ISPRITE_H */
