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


#include <IRectangle.h>

IRectangle::IRectangle(IRenderer *_pRenderer, s_nbPixels _width, s_nbPixels _height, s_pixel _colour, s_coord2d _topLeftPos)
: m_pRenderer(nullptr)
, m_width(_width)
, m_height(_height)
, m_colour(_colour)
, m_topLeftPos(_topLeftPos)
{
    m_pRenderer = _pRenderer;
}

IRectangle::~IRectangle()
{

}

void IRectangle::draw()
{

}

s_nbPixels IRectangle::getHeight()
{
    return m_height;
}

void IRectangle::setHeight(s_nbPixels _height)
{
    m_height = _height;
}