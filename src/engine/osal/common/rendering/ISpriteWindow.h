/*
 * The <unnamed> factory builder project.
 *
 * \file src/osal/common/rendering/ISpriteWindow.h
 *
 * \brief A sprite window is the field of view displayed, for a given sprite.
 */

/*
 * CHANGELOG:
 * 27/04/2024: File creation (NG)
 */

#ifndef _ENGINE_OSAL_COMMON_RENDERING_ISPRITEWINDOW_H
#define _ENGINE_OSAL_COMMON_RENDERING_ISPRITEWINDOW_H

#include <Types.h>
#include <ISprite.h>
#include <ISpriteRenderer.h>
#include <IRenderer.h>

class ISpriteWindow
{
public:
    ISpriteWindow(ISprite *_sprite, IRenderer *_pRenderer, s_coord2d _fovStartingPoint, s_nbPixels _width, s_nbPixels _height);
    virtual ~ISpriteWindow() = 0;

    virtual void changeFOV(s_coord2d _fovStartingPoint, s_nbPixels _width, s_nbPixels _height) = 0;

    ISprite *getSprite();

    virtual void draw(s_coord2d _startCoords, s_zoomRatio _zoomRatio) = 0;

    virtual void draw(s_coord2d _startCoords, s_nbPixels _width, s_nbPixels _height) = 0;

    void setupRendering(s_coord2d _textureLocation, s_zoomRatio _zoomRatio, s_nbPixels _screenWidth, s_nbPixels _screenHeight);

protected:
    s_coord2d m_fovStartingPoint;

    s_nbPixels m_fullWidth;
    s_nbPixels m_fullHeight;

    s_nbPixels m_renderingWidth;
    s_nbPixels m_renderingHeight;

    s_coord2d m_renderingOffset;

    ISprite *m_pSprite;

    IRenderer *m_pRenderer;

};

#endif /* End _ENGINE_OSAL_COMMON_RENDERING_ISPRITEWINDOW_H */