/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IOverlay.h
 *
 * \brief An abstract class for menu and other overlays implementation.
 */

/*
 * CHANGELOG:
 * 09/06/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_IOVERLAY_H
#define _ENGINE_CORE_IOVERLAY_H

#include <Types.h>
#include <PlayerKeyboardRoute.h>
#include <IOverlayInterface.h>
#include <IPlayerDisplayInterface.h>
#include <Rectangle.h>

class IOverlay : public IOverlayInterface
{
public:
    IOverlay(s_uuid _uuid, IRenderer *_pRenderer, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay);
    ~IOverlay();

    bool clickWithinOverlay(s_coord2d _clickCoordinates);

    virtual ePlayerKeyboardRoute processClick(s_coord2d _clickCoordinates) = 0;

    void draw();

protected:
    IPlayerDisplayInterface *m_pDisplay;
    s_nbPixels m_overlayWidth;
    s_nbPixels m_overlayHeight;

    s_coord2d m_overlayTopLeftPos;

    IRectangle *m_pBackground;
};

#endif