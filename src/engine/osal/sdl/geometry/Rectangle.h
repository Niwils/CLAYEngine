/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/osal/sdl/geometry/Rectanglez.h
 *
 * \brief The concrete implementation of a rectangle.
 */

/*
 * CHANGELOG:
 * 23/03/2024: File creation (NG)
 */

#ifndef _OSAL_SDL_RECTANGLE_H
#define _OSAL_SDL_RECTANGLE_H

#include <IRectangle.h>
#include <SDL2/SDL.h>
#include <Renderer.h>

/**
 * \brief This is the abstract class for the Game Model (floor tiles, manufacturing machine, conveyors and their respective contents)
*/
class Rectangle : public IRectangle
{
public:
    Rectangle(IRenderer *_pRenderer, s_nbPixels _width, s_nbPixels _height, s_pixel _colour, s_coord2d _topLeftPos);

    ~Rectangle();

    void draw();

private:

    SDL_Rect m_rectangle;
};

#endif /** End of _OSAL_SDL_RECTANGLE_H */