/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/rendering/Sprite.cpp/Sprite.cpp
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 14/04/2024: File creation (NG)
 */

#include <Sprite.h>


Sprite::Sprite(SDL_Texture *_pTexture, s_nbPixels _height, s_nbPixels _width, s_nbPixels _length, s_nbFrames _nbFrames, s_coord2d _center)
: ISprite(_height, _width, _length, _nbFrames, _center)
{
	
	m_pFullSprite = _pTexture;
}

Sprite::~Sprite()
{

}

SDL_Texture *Sprite::getTexture()
{
	return m_pFullSprite;
}