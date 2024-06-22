/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/overlays/MainGameBar.cpp
 *
 * \brief The top bar shown ingame.
 */

/*
 * CHANGELOG:
 * 15/06/2024: File creation (NG)
 */

#include <Button.h>

Button::Button(IRenderer *_pRenderer, s_nbPixels _buttonWidth, s_nbPixels _buttonHeight, s_coord2d _buttonPos)
: m_pRectangle(nullptr)
, m_topLeft(_buttonPos)
, m_width(_buttonWidth)
, m_height(_buttonHeight)
{
    m_pRectangle = new Rectangle(_pRenderer, _buttonWidth, _buttonHeight,  0x00FF00FF, _buttonPos);
}

Button::~Button()
{  
    delete m_pRectangle;
}

void Button::processClick(s_coord2d _clickCoordinates)
{
    
}

bool Button::clickWithinButton(s_coord2d _clickCoordinates)
{
    bool l_ret = false;

    if((m_topLeft.x <= _clickCoordinates.x)
        && ((m_topLeft.x + m_width) >=_clickCoordinates.x)
        && (m_topLeft.y <= _clickCoordinates.y)
        && ((m_topLeft.y + m_height) >=_clickCoordinates.y)
        )
        {
            l_ret = true;
        }

    return l_ret;
}

void Button::draw()
{
    m_pRectangle->draw();
}