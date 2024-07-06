/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/overlays/MainGameBar.h
 *
 * \brief The top bar shown ingame.
 */

/*
 * CHANGELOG:
 * 15/06/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_OVERLAYS_MAINGAMEBAR_H
#define _ENGINE_CORE_OVERLAYS_MAINGAMEBAR_H

#include <Types.h>
#include <IPopup.h>
#include <ObjList.h>
#include <SpriteButton.h>
#include <IPlayerDisplayInterface.h>
#include <PlayerSettingsMenu.h>
#include <MenuSpritesContainer.h>

class MainGameBar : public IOverlay
{
public:
    MainGameBar(s_uuid _uuid, IRenderer *_pRenderer, MenuSpritesContainer *_pSprites, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay);
    ~MainGameBar();

    ePlayerKeyboardRoute processClick(s_coord2d _clickCoordinates);

    void draw();

    bool clickWithinOverlay(s_coord2d _clickCoordinates);

protected:

    void drawBuildMenu();

    SpriteButton *m_pBuildingMenuButton;
    SpriteButton *m_pSettingsButton;

    MenuSpritesContainer *m_pSprites;
    
    enum eMainGameBar_openRollingMenu
    {
        eMainGameBar_openRollingMenu_None,
        eMainGameBar_openBuildMachine
    };

    eMainGameBar_openRollingMenu m_menuState;

    // Animation-related variables
    const s_Tick c_nb_ticks_to_unroll = 8; // Quarter of a second animation
    s_Tick m_nbTicksForCurrentAnimation;

    s_nbPixels m_height_increment_per_frame;

    // Rolling menu rectangle
    IRectangle *m_pRollingMenu;
    SpriteButton *m_pBuildItemProcessor;

};

#endif /** End of _ENGINE_CORE_OVERLAYS_MAINGAMEBAR_H */