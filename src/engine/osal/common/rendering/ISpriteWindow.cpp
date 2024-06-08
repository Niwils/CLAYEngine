/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/rendering/ISpriteWindow.cpp
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 27/04/2024: File creation (NG)
 */

#include <ISpriteWindow.h>

ISpriteWindow::ISpriteWindow(ISprite *_sprite, s_coord2d _fovStartingPoint, s_nbPixels _width, s_nbPixels _height)
{
    m_pSprite = _sprite;
    m_fovStartingPoint = _fovStartingPoint;
    m_fullWidth = _width;
    m_fullHeight = _height;

    m_renderingWidth = _width;
    m_renderingHeight = _height;

    m_renderingOffset.x = 0U;
    m_renderingOffset.y = 0U;
}

ISpriteWindow::~ISpriteWindow()
{

}

void ISpriteWindow::changeFOV(s_coord2d _fovStartingPoint, s_nbPixels _width, s_nbPixels _height)
{

}

ISprite *ISpriteWindow::getSprite()
{
    return m_pSprite;
}

void ISpriteWindow::setupRendering(s_coord2d _textureLocation, s_zoomRatio _zoomRatio, s_nbPixels _screenWidth, s_nbPixels _screenHeight)
{
    if(0U <= _zoomRatio)
    {
        _zoomRatio = 1U;
    }
    // Clean-up: removing previous frame settings
    m_renderingWidth = m_fullWidth;
    m_renderingHeight = m_fullHeight;

    s_nbPixels l_renderingWidthWithZoom = m_renderingWidth / _zoomRatio;
    s_nbPixels l_renderingHeightWithZoom = m_renderingHeight / _zoomRatio;

    m_renderingOffset.x = 0U;
    m_renderingOffset.y = 0U;

    // Texture is at the upper left of the window.
    
    // Input coordinates as the center of the floor tile. We get the upper-left pixel as (0;0)
    // TODO deal with the tiles with an height above zero (i.e. machining equipment...)
    s_nbPixels l_xOffset = l_renderingWidthWithZoom/2;
    s_nbPixels l_yOffset = l_renderingHeightWithZoom/2;

    // Calculating the theoretical location of a full sprite, without window limitations.
    s_coord2d l_textureTopLeft;

    l_textureTopLeft.x = (_textureLocation.x-l_xOffset);
    l_textureTopLeft.y = (_textureLocation.y-l_yOffset);

    s_coord2d l_textureBottomRight;

    l_textureBottomRight.x = (_textureLocation.x+l_xOffset);
    l_textureBottomRight.y = (_textureLocation.y+l_yOffset);

    // Full texture would be out-of-screen from the left or top sides. Here we truncate the FOV to fit the screen.
  /*  if(0 > l_textureTopLeft.x)
    {
        m_renderingOffset.x = (0-l_textureTopLeft.x)*_zoomRatio; // Cropping the source texture (full ratio, hence *_zoomRatio)
        m_renderingWidth = m_renderingWidth + (l_textureTopLeft.x*_zoomRatio);
    }

    if(0 > l_textureTopLeft.y)
    {
        m_renderingOffset.y = (0-l_textureTopLeft.y)*_zoomRatio;
        m_renderingHeight = m_renderingHeight + (l_textureTopLeft.y*_zoomRatio);
    }
*/
    // Full texture would be out-of-screen from the right or bottom sides. Here we truncate the FOV to fit the screen.
 /*   if(_screenWidth <= l_textureBottomRight.x)
    {
        m_renderingWidth = m_renderingWidth - ((_screenWidth - l_textureBottomRight.x)*_zoomRatio);
    }

    if(_screenHeight <= l_textureBottomRight.y)
    {
        m_renderingHeight = m_renderingHeight - ((_screenHeight - l_textureBottomRight.y)*_zoomRatio);
    }*/
}