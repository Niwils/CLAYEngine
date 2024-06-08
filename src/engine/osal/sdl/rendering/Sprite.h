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

#ifndef _ENGINE_OSAL_SDL_RENDERING_SPRITE_H
#define _ENGINE_OSAL_SDL_RENDERING_SPRITE_H

#include <ISprite.h>
#include <SDL2/SDL.h>
// #include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_video.h>

class Sprite : public ISprite
{
public:
	Sprite(SDL_Texture *_pTexture, s_nbPixels _height, s_nbPixels _width, s_nbPixels _length, s_nbFrames _nbFrames, s_coord2d _center);
	~Sprite();

	SDL_Texture *getTexture();

private:
	SDL_Texture *m_pFullSprite;
};

#endif /* End _ENGINE_OSAL_SDL_RENDERING_SPRITE_H */
