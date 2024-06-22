/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/osal/sdl/geometry/Rectangle.h
 *
 * \brief The abstract implementation of a rectangle.
 */

/*
 * CHANGELOG:
 * 09/06/2024: File creation (NG)
 */

#ifndef _OSAL_COMMON_IRECTANGLE_H
#define _OSAL_COMMON_IRECTANGLE_H

#include <Types.h>
#include <IRenderer.h>

/**
 * \brief This is the abstract class for the Game Model (floor tiles, manufacturing machine, conveyors and their respective contents)
*/
class IRectangle
{
public:
    IRectangle(IRenderer *_pRenderer, s_nbPixels _width, s_nbPixels _height, s_pixel _colour, s_coord2d _topLeftPos);

    virtual ~IRectangle() = 0;

    virtual void draw() = 0;

    s_nbPixels getHeight();

    void setHeight(s_nbPixels _height);

protected:
    s_nbPixels m_width;
    s_nbPixels m_height;

    s_pixel m_colour;

    s_coord2d m_topLeftPos;

    IRenderer *m_pRenderer;
};

#endif /** End of _OSAL_COMMON_IRECTANGLE_H */