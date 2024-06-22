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

#ifndef _ENGINE_CORE_IOVERLAYINTERFACE_H
#define _ENGINE_CORE_IOVERLAYINTERFACE_H

#include <Types.h>
#include <PlayerKeyboardRoute.h>
#include <IRenderer.h>


class IOverlayInterface
{
public:
    IOverlayInterface(s_uuid _uuid, IRenderer *_pRenderer);
    ~IOverlayInterface();

    virtual bool clickWithinOverlay(s_coord2d _clickCoordinates) = 0;

    virtual ePlayerKeyboardRoute processClick(s_coord2d _clickCoordinates) = 0;

    virtual void draw() = 0;

    s_uuid getUuid();

    void setUuid(s_uuid _uuid);

protected:
    s_uuid m_uuid;

    IRenderer *m_pRenderer;
};

#endif /** End of _ENGINE_CORE_IOVERLAYINTERFACE_H */