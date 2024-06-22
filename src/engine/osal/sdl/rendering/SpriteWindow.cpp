/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/sdl/rendering/ISpriteWindow.cpp
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 27/04/2024: File creation (NG)
 */

#include <SpriteWindow.h>

SpriteWindow::SpriteWindow(ISprite *_sprite, IRenderer *_pRenderer, s_coord2d _fovStartingPoint, s_nbPixels _width, s_nbPixels _height)
: ISpriteWindow(_sprite, _pRenderer, _fovStartingPoint, _width, _height)
{
    
}

SpriteWindow::~SpriteWindow()
{

}

void SpriteWindow::changeFOV(s_coord2d _fovStartingPoint, s_nbPixels _width, s_nbPixels _height)
{

}

void SpriteWindow::draw(s_coord2d _centerCoords, s_zoomRatio _zoomRatio)
{
    Renderer *l_pRenderer = static_cast<Renderer *>(m_pRenderer);

    Sprite *l_pSprite = static_cast<Sprite *>(m_pSprite);

    SDL_Texture *l_pTexture = l_pSprite->getTexture();

	SDL_Rect l_src = this->getShownSpriteArea();
	SDL_Rect l_dst = this->getDisplayableArea(_centerCoords, _zoomRatio);

    SDL_Renderer *l_pSdlRenderer = l_pRenderer->getRenderer();
	SDL_RenderCopy(l_pSdlRenderer, l_pTexture, &l_src, &l_dst);
}

void SpriteWindow::draw(s_coord2d _startCoords, s_nbPixels _width, s_nbPixels _height)
{
    Renderer *l_pRenderer = static_cast<Renderer *>(m_pRenderer);

    Sprite *l_pSprite = static_cast<Sprite *>(m_pSprite);

    SDL_Texture *l_pTexture = l_pSprite->getTexture();

	SDL_Rect l_src = this->getShownSpriteArea();
	SDL_Rect l_dst;

    l_dst.x = _startCoords.x-(0.5*_width);
    l_dst.y = _startCoords.y-(0.5*_height);
    l_dst.h = _height;
    l_dst.w = _width;

    SDL_Renderer *l_pSdlRenderer = l_pRenderer->getRenderer();
	SDL_RenderCopy(l_pSdlRenderer, l_pTexture, &l_src, &l_dst);
}

SDL_Rect SpriteWindow::getShownSpriteArea()
{

    SDL_Rect l_displayFOV;

    l_displayFOV.x = m_renderingOffset.x;
    l_displayFOV.y = m_renderingOffset.y;
    l_displayFOV.h = m_renderingHeight;
    l_displayFOV.w = m_renderingWidth;

    return l_displayFOV;
}

SDL_Rect SpriteWindow::getDisplayableArea(s_coord2d _textureLocation, s_zoomRatio _zoomRatio)
{
    // TODO assert _zoomRatio different than zero.
    SDL_Rect l_rendererFOV;

    if(0 == _zoomRatio)
    {
        _zoomRatio = 1;
    }
    
    s_nbPixels l_renderingWidthWithZoom = m_renderingWidth / _zoomRatio;
    s_nbPixels l_renderingHeightWithZoom = m_renderingHeight / _zoomRatio;

    // TODO manage textures which height does not match the standard-tile height.
    l_rendererFOV.x = _textureLocation.x-(0.5*l_renderingWidthWithZoom);
    l_rendererFOV.y = _textureLocation.y-(0.5*l_renderingHeightWithZoom);
    l_rendererFOV.h = m_renderingHeight/_zoomRatio;
    l_rendererFOV.w = m_renderingWidth/_zoomRatio;

    return l_rendererFOV;
}