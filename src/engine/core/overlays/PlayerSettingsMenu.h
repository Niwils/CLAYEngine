/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/overlays/PlayerSettingsMenu.h
 *
 * \brief The ingame player settings menu.
 */

/*
 * CHANGELOG:
 * 16/06/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_OVERLAYS_PLAYERSETTINGSMENU_H
#define _ENGINE_CORE_OVERLAYS_PLAYERSETTINGSMENU_H

#include <Types.h>
#include <IPopup.h>
#include <SpriteButton.h>
#include <IPlayerDisplayInterface.h>
#include <MenuSpritesContainer.h>

class PlayerSettingsMenu : public IPopup
{
public:
    PlayerSettingsMenu(s_uuid _uuid, IRenderer *_pRenderer, MenuSpritesContainer *_pSprites, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay);
    ~PlayerSettingsMenu();

    ePlayerKeyboardRoute processClick(s_coord2d _clickCoordinates);

    void draw();

protected:    

};

#endif /** End of _ENGINE_CORE_OVERLAYS_PLAYERSETTINGSMENU_H */