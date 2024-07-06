/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/overlays/MainGameBar.cpp
 *
 * \brief The top bar shown ingame.
 */

/*
 * CHANGELOG:
 * 15/06/2024: File creation (NG)
 */

#include <MainGameBar.h>

MainGameBar::MainGameBar(s_uuid _uuid, IRenderer *_pRenderer, MenuSpritesContainer *_pSprites, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay)
: IOverlay(_uuid, _pRenderer, _overlayWidth, _overlayHeight, _overlayTopLeftPos, _pDisplay)
, m_pSettingsButton(nullptr)
, m_pSprites(nullptr)
, m_menuState(eMainGameBar_openRollingMenu_None)
, m_nbTicksForCurrentAnimation(0U)
, m_pRollingMenu(nullptr)
, m_height_increment_per_frame(5*_overlayHeight/c_nb_ticks_to_unroll)
, m_pBuildItemProcessor(nullptr)
{
    s_coord2d l_settingsButtonCoords;
    l_settingsButtonCoords.x = _overlayTopLeftPos.x;
    l_settingsButtonCoords.y = _overlayTopLeftPos.y;

    m_pSprites = _pSprites;

    ISprite *l_settingsSprite = m_pSprites->getSprite(eMenuSpritesContainer_settings);
    m_pSettingsButton = new SpriteButton(_pRenderer, l_settingsSprite, m_overlayHeight, m_overlayHeight, l_settingsButtonCoords, 0xFFFFFFFF);

    l_settingsButtonCoords.x = _overlayTopLeftPos.x + m_overlayHeight;

    ISprite *l_buildMenuSprite = m_pSprites->getSprite(eMenuSpritesContainer_build);
    m_pBuildingMenuButton = new SpriteButton(_pRenderer, l_buildMenuSprite, m_overlayHeight, m_overlayHeight, l_settingsButtonCoords, 0xFFFFFFFF);
    
    l_settingsButtonCoords.y = _overlayTopLeftPos.y + m_overlayHeight;
    ISprite *l_buildMenuBuildProcessor = m_pSprites->getSprite(eMenuSpritesContainer_build_manufacturing);
    m_pBuildItemProcessor = new SpriteButton(_pRenderer, l_buildMenuBuildProcessor, m_overlayHeight, m_overlayHeight, l_settingsButtonCoords, 0xFFFFFFFF);
}

MainGameBar::~MainGameBar()
{
    delete m_pSettingsButton;

    delete m_pBuildingMenuButton;
}

bool MainGameBar::clickWithinOverlay(s_coord2d _clickCoordinates)
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
    else if((eMainGameBar_openBuildMachine == m_menuState)
        && ((m_overlayTopLeftPos.x+m_overlayHeight) <= _clickCoordinates.x)
        && ((m_overlayTopLeftPos.x+2*m_overlayHeight) >= _clickCoordinates.x)
        && ((m_overlayTopLeftPos.y+m_overlayHeight) <= _clickCoordinates.y)
        && ((m_overlayTopLeftPos.y+5*m_overlayHeight) >= _clickCoordinates.y)
        )
    {
        l_ret = true;
    }

    return l_ret;
}

ePlayerKeyboardRoute MainGameBar::processClick(s_coord2d _clickCoordinates)
{  
    if(true == m_pSettingsButton->clickWithinButton(_clickCoordinates))
    {
        s_coord2d l_popCoords;
        l_popCoords.x = 512;
        l_popCoords.y = 100;
        s_uuid l_uuid = m_pDisplay->getNewOverlayUuid();
        IPopup *l_pNewPopup = new PlayerSettingsMenu(l_uuid, m_pRenderer, m_pSprites, 200, 200, l_popCoords, m_pDisplay);
        m_pDisplay->createOverlay(l_pNewPopup);
    }

    if(eMainGameBar_openRollingMenu_None == m_menuState)
    {
        if(true == m_pBuildingMenuButton->clickWithinButton(_clickCoordinates))
        {
            m_nbTicksForCurrentAnimation = 0;

            s_coord2d l_rollingMenuCoords = m_overlayTopLeftPos;
            l_rollingMenuCoords.x += m_overlayHeight;
            l_rollingMenuCoords.y += m_overlayHeight;
            m_pRollingMenu = new Rectangle(m_pRenderer, m_overlayHeight, 1U, 0xFFFFFFFF, l_rollingMenuCoords);
            m_menuState = eMainGameBar_openBuildMachine;
        }
    }
    else if(eMainGameBar_openBuildMachine == m_menuState)
    {  
        if(true == m_pBuildingMenuButton->clickWithinButton(_clickCoordinates))
        {
            m_menuState = eMainGameBar_openRollingMenu_None;
            delete m_pRollingMenu;
        }

        if(true == m_pBuildItemProcessor->clickWithinButton(_clickCoordinates))
        {
            m_menuState=eMainGameBar_openRollingMenu_None;
            delete m_pRollingMenu;
            // TODO open item processor invokation menu.
        }
    }
  
    return ePlayerKeyboardRoute_Camera;
}

void MainGameBar::draw()
{
    IOverlay::draw();
    m_pSettingsButton->draw();
    m_pBuildingMenuButton->draw();

    switch(m_menuState)
    {
        case eMainGameBar_openBuildMachine:
        {
            drawBuildMenu();
            break;
        }

        default:
            // Do nothing
            break;
    }
}

void MainGameBar::drawBuildMenu()
{
    if(nullptr != m_pRollingMenu)
    {
        if(c_nb_ticks_to_unroll > m_nbTicksForCurrentAnimation)
        {
            s_nbPixels l_menuHeight = m_pRollingMenu->getHeight();
            m_pRollingMenu->setHeight(l_menuHeight+m_height_increment_per_frame);
            m_nbTicksForCurrentAnimation++;
        }

        m_pRollingMenu->draw();

        if(m_overlayHeight < m_pRollingMenu->getHeight())
        {
            m_pBuildItemProcessor->draw();
        }
    }
}