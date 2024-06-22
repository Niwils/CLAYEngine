/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IOverlay.cpp
 *
 * \brief An abstract class for menu and other overlays implementation.
 */

/*
 * CHANGELOG:
 * 09/06/2024: File creation (NG)
 */

#include <IPopup.h>

IPopup::IPopup(s_uuid _uuid, IRenderer *_pRenderer, ISprite *_pCloseWindowSprite, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay)
: IOverlay(_uuid, _pRenderer, _overlayWidth, _overlayHeight, _overlayTopLeftPos, _pDisplay)
, m_pTopBar(nullptr)
, m_closeButton(nullptr)
{
    // TODO assert _pDisplay is not null.

    m_pTopBar = new Rectangle(_pRenderer, _overlayWidth, 10, 0x00FF00FF, m_overlayTopLeftPos);

    s_coord2d l_closeButtonPos;

    l_closeButtonPos.x = m_overlayTopLeftPos.x + m_overlayWidth - 10;
    l_closeButtonPos.y = m_overlayTopLeftPos.y;

    m_closeButton = new SpriteButton(_pRenderer, _pCloseWindowSprite, 10, 10, l_closeButtonPos, 0x00FF00FF);
}

IPopup::~IPopup()
{

}

bool IPopup::clickWithinOverlay(s_coord2d _clickCoordinates)
{
    return IOverlay::clickWithinOverlay(_clickCoordinates);
}

ePlayerKeyboardRoute IPopup::processClick(s_coord2d _clickCoordinates)
{
    
}

void IPopup::draw()
{  
    IOverlay::draw(); // Drawing the background.

    m_pTopBar->draw();

    m_closeButton->draw();
}