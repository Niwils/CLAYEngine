/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/overlays/PlayerSettingsMenu.cpp
 *
 * \brief The top bar shown ingame.
 */

/*
 * CHANGELOG:
 * 15/06/2024: File creation (NG)
 */

#include <PlayerSettingsMenu.h>

PlayerSettingsMenu::PlayerSettingsMenu(s_uuid _uuid, IRenderer *_pRenderer, MenuSpritesContainer *_pSprites, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay)
: IPopup(_uuid, _pRenderer, _pSprites, _overlayWidth, _overlayHeight, _overlayTopLeftPos, _pDisplay)
{
    s_coord2d l_settingsButtonCoords;
    l_settingsButtonCoords.x = _overlayTopLeftPos.x;
    l_settingsButtonCoords.y = _overlayTopLeftPos.y;
}

PlayerSettingsMenu::~PlayerSettingsMenu()
{

}

ePlayerKeyboardRoute PlayerSettingsMenu::processClick(s_coord2d _clickCoordinates)
{
    if(true == m_pCloseButton->clickWithinButton(_clickCoordinates))
    {
        m_pDisplay->removeOverlay(m_uuid);
    }
    // TODO Manage rectangle : drag and drop.
}

void PlayerSettingsMenu::draw()
{
    IPopup::draw();
}