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

#ifndef _ENGINE_CORE_IPOPUP_H
#define _ENGINE_CORE_IPOPUP_H

#include <Types.h>
#include <PlayerKeyboardRoute.h>
#include <IOverlay.h>
#include <ObjList.h>
#include <SpriteButton.h>

class IPopup : public IOverlay
{
public:
    IPopup(s_uuid _uuid, IRenderer *_pRenderer, ISprite *_pCloseWindowSprite, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay);
    ~IPopup();

    bool clickWithinOverlay(s_coord2d _clickCoordinates);

    virtual ePlayerKeyboardRoute processClick(s_coord2d _clickCoordinates) = 0;

    void draw();

protected:
    SpriteButton *m_closeButton;

    IRectangle *m_pTopBar;
};

#endif /** End of _ENGINE_CORE_IPOPUP_H */