/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/osal/sdl/geometry/IRectangle.cpp
 *
 * \brief The abstract implementation of a rectangle.
 */

/*
 * CHANGELOG:
 * 09/06/2024: File creation (NG)
 */


#include <Rectangle.h>

Rectangle::Rectangle(IRenderer *_pRenderer, s_nbPixels _width, s_nbPixels _height, s_pixel _colour, s_coord2d _topLeftPos)
: IRectangle(_pRenderer, _width, _height, _colour, _topLeftPos)
{
    m_rectangle.x = m_topLeftPos.x;
    m_rectangle.y = m_topLeftPos.y;
    m_rectangle.w = m_width;
    m_rectangle.h = m_height;
}

Rectangle::~Rectangle()
{

}

void Rectangle::draw()
{
    Renderer *l_pRectangle = static_cast<Renderer *>(m_pRenderer);

    SDL_Renderer *l_pSdlRenderer = l_pRectangle->getRenderer();

    s_pixel l_red = (m_colour>>24U)&0x000000FF;
    s_pixel l_green = (m_colour>>16U)&0x000000FF;
    s_pixel l_blue = (m_colour>>8U)&0x000000FF;
    s_pixel l_alpha = (m_colour)&0x000000FF;

    SDL_SetRenderDrawColor(l_pSdlRenderer, l_red, l_green, l_blue, l_alpha);

    SDL_Rect l_rect;
    l_rect.x = m_topLeftPos.x;
    l_rect.y = m_topLeftPos.y;
    l_rect.w = m_width;
    l_rect.h = m_height;
    SDL_RenderFillRect(l_pSdlRenderer, &l_rect);
}