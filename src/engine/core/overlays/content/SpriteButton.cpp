/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/overlays/SpriteButton.cpp
 *
 * \brief The top bar shown ingame.
 */

/*
 * CHANGELOG:
 * 15/06/2024: File creation (NG)
 */

#include <SpriteButton.h>

SpriteButton::SpriteButton(IRenderer *_pRenderer, ISprite *_pSprite, s_nbPixels _buttonWidth, s_nbPixels _buttonHeight, s_coord2d _buttonPos, s_pixel _bgColour)
: Button(_pRenderer, _buttonWidth, _buttonHeight, _buttonPos)
, m_spritePosition(_buttonPos)
, m_spriteRatio(1U)
, m_pSprite(nullptr)
{
    s_coord2d l_buttonCentralPos;
    l_buttonCentralPos.x = 0.5*_buttonWidth;
    l_buttonCentralPos.y = 0.5*_buttonHeight;

    m_spritePosition.x += l_buttonCentralPos.x,
    m_spritePosition.y += l_buttonCentralPos.y;

    m_spriteRatio = _pSprite->getWidth()/_buttonWidth;

    m_pRectangle = new Rectangle(_pRenderer, _buttonWidth, _buttonHeight, _bgColour, _buttonPos);
    m_pSprite = new SpriteWindow(_pSprite, _pRenderer, l_buttonCentralPos, _pSprite->getWidth(), _pSprite->getHeight());
}

SpriteButton::~SpriteButton()
{  
    delete m_pSprite;
    Button::~Button();
}

void SpriteButton::processClick(s_coord2d _clickCoordinates)
{
    
}

bool SpriteButton::clickWithinButton(s_coord2d _clickCoordinates)
{
    return Button::clickWithinButton(_clickCoordinates);
}

void SpriteButton::draw()
{
    m_pRectangle->draw();

    m_pSprite->draw(m_spritePosition, m_width, m_height);
}