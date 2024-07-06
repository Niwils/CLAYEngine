/*!
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

#include <IOverlayInterface.h>

IOverlayInterface::IOverlayInterface(s_uuid _uuid, IRenderer *_pRenderer)
: m_uuid(_uuid)
, m_pRenderer(nullptr)
{
    m_pRenderer = _pRenderer;
}

IOverlayInterface::~IOverlayInterface()
{

}

bool IOverlayInterface::clickWithinOverlay(s_coord2d _clickCoordinates)
{
}

ePlayerKeyboardRoute IOverlayInterface::processClick(s_coord2d _clickCoordinates)
{
    
}

void IOverlayInterface::draw()
{

}

s_uuid IOverlayInterface::getUuid()
{
    return m_uuid;
}

void IOverlayInterface::setUuid(s_uuid _uuid)
{
    m_uuid = _uuid;
}