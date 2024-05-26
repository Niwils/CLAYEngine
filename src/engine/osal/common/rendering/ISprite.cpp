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

#include <ISprite.h>


ISprite::ISprite(s_nbPixels _height, s_nbPixels _width, s_nbPixels _length, s_nbFrames _nbFrames, s_coord2d _center)
{
	m_height = _height;
	m_width = _width;
	m_length = _length;
	m_nbFrames = _nbFrames;
	m_spriteDisplayCoord = _center;
	// TODO check the number of frames expected vs the image size.
}

ISprite::~ISprite()
{

}

s_coord2d ISprite::getDisplayOrigin()
{

}

s_nbPixels ISprite::getHeight()
{
	return m_height;
}

s_nbPixels ISprite::getWidth()
{
	return m_width;
}

s_nbPixels ISprite::getLength()
{
 return m_length;
}

s_nbFrames ISprite::getNbFrames()
{
	return m_nbFrames;
}