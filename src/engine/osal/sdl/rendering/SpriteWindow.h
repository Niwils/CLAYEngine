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

#ifndef _ENGINE_OSAL_SDL_RENDERING_SPRITEWINDOW_H
#define _ENGINE_OSAL_SDL_RENDERING_SPRITEWINDOW_H

#include <Types.h>
#include <ISpriteWindow.h>
#include <Sprite.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

class SpriteWindow : public ISpriteWindow
{
public:
    SpriteWindow(ISprite *_sprite, s_coord2d _fovStartingPoint, s_nbPixels _width, s_nbPixels _height);
    ~SpriteWindow();

    void changeFOV(s_coord2d _fovStartingPoint, s_nbPixels _width, s_nbPixels _height);

	void draw(s_coord2d _startCoords, SDL_Surface *_dest);

    SDL_Rect getShownSpriteArea();

    SDL_Rect getDisplayableArea(s_coord2d _textureLocation, s_zoomRatio _zoomRatio);

protected:


};

#endif /* End _ENGINE_OSAL_SDL_RENDERING_ISPRITEWINDOW_H */