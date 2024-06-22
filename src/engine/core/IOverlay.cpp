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

#include <IOverlay.h>

IOverlay::IOverlay(s_uuid _uuid, IRenderer *_pRenderer, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay)
: IOverlayInterface(_uuid, _pRenderer)
, m_pDisplay(nullptr)
, m_overlayWidth(_overlayWidth)
, m_overlayHeight(_overlayHeight)
, m_overlayTopLeftPos(_overlayTopLeftPos)
, m_pBackground(nullptr)
{
    // TODO assert _pDisplay is not null.

    m_pDisplay = _pDisplay;

    // TODO add coulout as a parameter
    m_pBackground = new Rectangle(_pRenderer, _overlayWidth, _overlayHeight, 0xFFFFFFFF, _overlayTopLeftPos);

}

IOverlay::~IOverlay()
{

}

bool IOverlay::clickWithinOverlay(s_coord2d _clickCoordinates)
{
    bool l_ret = false;

    if((m_overlayTopLeftPos.x <= _clickCoordinates.x)
        && ((m_overlayTopLeftPos.x+m_overlayWidth) >= _clickCoordinates.x)
        && (m_overlayTopLeftPos.y <= _clickCoordinates.y)
        && ((m_overlayTopLeftPos.y+m_overlayHeight) >= _clickCoordinates.y)
    )
    {
        l_ret = true;
    }

    return l_ret;
}

ePlayerKeyboardRoute IOverlay::processClick(s_coord2d _clickCoordinates)
{
    
}

void IOverlay::draw()
{  
    m_pBackground->draw();
}