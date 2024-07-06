/*!
 * The CLAYEngine project.
 *
 * @file /src/engine/graph/IGraph.h
 *
 * @brief The view object of the MVC model.
 *
 */

/*
 * CHANGELOG:
 * 17/03/2024: File creation (NG)
 */

#include <PlayerDisplay.h>

PlayerDisplay::PlayerDisplay(IOsalSys *_pOsalSys, IRenderer *_pRenderer, PlayerSettings *_pPlayerSettings)
: m_pOsalSys(_pOsalSys)
, m_pRenderer(nullptr)
, m_pPlayerSettings(_pPlayerSettings)
, m_displayMode()
, m_pCamera(nullptr)
, m_gameQuitRequested(false)
, m_pOverlaySprite(nullptr)
, m_pOverlaySpriteWindow(nullptr)
, m_overlayUuidCounter(0U)
, m_pOverlayVector(nullptr)
, m_pSprites(nullptr)
{
	m_pRenderer = _pRenderer;
	m_pOverlayVector = new std::vector<IOverlayInterface *>();
	m_pSprites = new MenuSpritesContainer();
}

PlayerDisplay::~PlayerDisplay()
{
	delete m_pOverlaySprite;
	delete m_pOverlayVector; // TODO clean the vector in a better way.
	delete m_pSprites;
}

s_errorReturn PlayerDisplay::createWindow()
{
	s_playerWindowWidth l_width = m_pPlayerSettings->getDisplayWidth();

	s_playerWindowWidth l_height = m_pPlayerSettings->getDisplayHeight();

	s_errorReturn l_ret = m_pOsalSys->createNewWindow(l_width, l_height);

	return l_ret;
}

void PlayerDisplay::setModel(IGameModel *_pModel)
{
	m_pPlayerCompany = _pModel;
}

void PlayerDisplay::parseInputs()
{
	// TODO assert m_pOsalSys is not null.
	m_pOsalSys->getAndParseEvents();

	m_gameQuitRequested = m_pOsalSys->isWindowCloseRequested();

	std::vector<KeyboardEvent *> *l_keyEvents = m_pOsalSys->getKeyboardEvents();

	std::vector<KeyboardEvent *>::iterator l_it = l_keyEvents->begin();

	while(l_it != l_keyEvents->end())
	{
		ePlayerActions l_action;
		KeyboardEvent *l_event = *(l_it);
		l_action = this->parseKeyToAction(l_event->getKey());
		this->processPlayerAction(l_action);
		l_it++;
	}

	std::vector<MouseEvent *> *l_mouseEvents = m_pOsalSys->getMouseEvents();

	std::vector<MouseEvent *>::iterator l_mouseIt = l_mouseEvents->begin();

	while(l_mouseIt != l_mouseEvents->end())
	{
		ePlayerActions l_action;
		MouseEvent *l_event = *(l_mouseIt);
		l_action = this->parseMouseKeyToAction(l_event->getKey());
		this->processPlayerAction(l_action);

		m_mouseCoordinates = l_event->getCoordinates();
		m_pCamera->setMousePointerCoords(m_mouseCoordinates);

		l_mouseIt++;
	}

	m_pOsalSys->flushEvents();
}

void PlayerDisplay::update()
{
	switch(m_displayMode)
	{
		case ePlayerDisplayMode_MainMenu:
		{
			// TODO
			break;
		};

		case ePlayerDisplayMode_InGame:
		{
			m_pOsalSys->setupBackgroundColor(0x000000FF);
			m_pOsalSys->clearWindow();
			m_pCamera->refreshCamera();

			// Updating overlays
			std::vector<IOverlayInterface *>::iterator l_it = m_pOverlayVector->begin();

			while(l_it != m_pOverlayVector->end())
			{
				IOverlayInterface *l_pOverlay = *(l_it)
;				l_pOverlay->draw();
				l_it++;
			}

			m_pOsalSys->updateWindow();
			break;
		};

		default:
			// TODO raise error
			break;
	};
}

void PlayerDisplay::parseEvent()
{

}

void PlayerDisplay::parseWindowEvent()
{

}

void PlayerDisplay::changePlayerFOV()
{

}

void PlayerDisplay::switchToMainMenu()
{
	m_displayMode = ePlayerDisplayMode_MainMenu;
}

void PlayerDisplay::switchToGameCamera()
{
	s_coord2d l_mouseOverlayCenterLoad;

	l_mouseOverlayCenterLoad.x = 212;
	l_mouseOverlayCenterLoad.y = 106;

	m_pOverlaySprite = m_pOsalSys->loadSprite("../assets/mapOverlay.bmp",
							424, 212, 0U, 1U, l_mouseOverlayCenterLoad);

	s_coord2d l_mouseOverlayCentre;
	l_mouseOverlayCentre.x = 0.5*(m_pOverlaySprite->getWidth());
	l_mouseOverlayCentre.y = 0.5*(m_pOverlaySprite->getHeight());

	m_pOverlaySpriteWindow = new SpriteWindow(m_pOverlaySprite, m_pRenderer,
												l_mouseOverlayCentre,
												m_pOverlaySprite->getHeight(),
												m_pOverlaySprite->getWidth()
											);

	m_pCamera = new PlayerCamera(m_pOsalSys, m_pPlayerSettings, m_pPlayerCompany, m_pOverlaySpriteWindow);

	m_pOsalSys->setupBackgroundColor(0x000000FF);
	m_pCamera->refreshCamera();
	s_coord2d l_overlayBarCoords;
	s_nbPixels l_overlayBarWidth = 0.75*m_pPlayerSettings->getDisplayWidth();
	s_nbPixels l_overlayBarHeight = 0.05*m_pPlayerSettings->getDisplayHeight();
	l_overlayBarCoords.x = 0.125*m_pPlayerSettings->getDisplayWidth();
	l_overlayBarCoords.y = 0;

	s_coord2d l_centerSprite;
	l_centerSprite.x = 27;
	l_centerSprite.y = 27;

	ISprite *l_settingsButtonSprite = m_pOsalSys->loadSprite("../assets/buttons/settings.bmp",
							54U, 54U, 0U, 1U, l_centerSprite);

	m_pSprites->addSprite(eMenuSpritesContainer_settings, l_settingsButtonSprite);

	ISprite *l_manufacturingEquipMenu = m_pOsalSys->loadSprite("../assets/buttons/build_processor.bmp",
							54U, 54U, 0U, 1U, l_centerSprite);

	m_pSprites->addSprite(eMenuSpritesContainer_build, l_manufacturingEquipMenu);

	ISprite *l_itemProcessorMenuSprite = m_pOsalSys->loadSprite("../assets/buttons/manufacturing.bmp",
							54U, 54U, 0U, 1U, l_centerSprite);

	m_pSprites->addSprite(eMenuSpritesContainer_build_manufacturing, l_itemProcessorMenuSprite);

	ISprite *l_closingPopupButton = m_pOsalSys->loadSprite("../assets/buttons/close.bmp",
							54U, 54U, 0U, 1U, l_centerSprite);

	m_pSprites->addSprite(eMenuSpritesContainer_closeButton, l_closingPopupButton);

	MainGameBar *l_pTopBarOverlay = new MainGameBar(0U, m_pRenderer, m_pSprites, l_overlayBarWidth, l_overlayBarHeight, l_overlayBarCoords, this);

	m_pOverlayVector->push_back(l_pTopBarOverlay);
	m_displayMode = ePlayerDisplayMode_InGame;
}

bool PlayerDisplay::gameQuitRequested()
{
	return m_gameQuitRequested;
}

ePlayerActions PlayerDisplay::parseKeyToAction(eKeyboardKeys _key)
{
	ePlayerActions l_ret;
	// TODO: call PlayerActionsMapping.
	switch(_key)
	{
		case eKeyboardKeys_upkey:
			l_ret = ePlayerActions_CameraTravellingUp;
			break;
		
		case eKeyboardKeys_downkey:
			l_ret = ePlayerActions_CameraTravellingDown;
			break;

		case eKeyboardKeys_leftkey:
			l_ret = ePlayerActions_CameraTravellingLeft;
			break;

		case eKeyboardKeys_rightkey:
			l_ret = ePlayerActions_CameraTravellingRight;
			break;

		default:
			l_ret = ePlayerActions_DoNothing;
			break;
	};

	return l_ret;
}

ePlayerActions PlayerDisplay::parseMouseKeyToAction(eMouseKeys _key)
{
	ePlayerActions l_ret;
	// TODO: call PlayerActionsMapping.
	switch(_key)
	{
		case eMouseKeys_LeftClick:
			l_ret = ePlayerActions_Click;
			break;
		
		case eMouseKeys_WheelUp:
			l_ret = ePlayerActions_Zoom;
			break;

		case eMouseKeys_WheelDown:
			l_ret = ePlayerActions_Unzoom;
			break;

		default:
			l_ret = ePlayerActions_DoNothing;
			break;
	};

	return l_ret;
}


void PlayerDisplay::processPlayerAction(ePlayerActions _action)
{
	switch(_action)
	{
		case ePlayerActions_CameraTravellingDown:
			m_pCamera->moveCameraDownwards();
			break;
		
		case ePlayerActions_CameraTravellingUp:
			m_pCamera->moveCameraUpwards();
			break;

		case ePlayerActions_CameraTravellingLeft:
			m_pCamera->moveCameraLeft();
			break;

		case ePlayerActions_CameraTravellingRight:
			m_pCamera->moveCameraRight();
			break;

		case ePlayerActions_Zoom:
			m_pCamera->zoomCamera();
			break;

		case ePlayerActions_Unzoom:
			m_pCamera->unzoomCamera();
			break;

		case ePlayerActions_Click:
		{
			processClick();
			break;
		}

		default:
			// Do nothing.
			break;
	};
}

void PlayerDisplay::processClick()
{
	std::vector<IOverlayInterface *>::iterator l_it = m_pOverlayVector->begin();

	bool l_clickFoundOnOverlay = false;

	while((l_it != m_pOverlayVector->end()) && (false == l_clickFoundOnOverlay))
	{
		IOverlayInterface *l_overlay = *(l_it);

		if(true == l_overlay->clickWithinOverlay(m_mouseCoordinates))
		{
			l_clickFoundOnOverlay = true;
			l_overlay->processClick(m_mouseCoordinates);
		}

		l_it++;
	}

	if(false == l_clickFoundOnOverlay)
	{
		m_pCamera->setMousePointerCoords(m_mouseCoordinates);
	}
	
}

void PlayerDisplay::createOverlay(IOverlayInterface *_pDisplay)
{
	m_pOverlayVector->push_back(_pDisplay);
}

void PlayerDisplay::removeOverlay(s_uuid _uuid)
{
	std::vector<IOverlayInterface*>::iterator l_it = m_pOverlayVector->begin();

	bool l_found = false;

	while((m_pOverlayVector->end() != l_it) && (false == l_found))
	{
		IOverlayInterface *l_intf = *(l_it);
		if(_uuid == l_intf->getUuid())
		{
			m_pOverlayVector->erase(l_it);
			l_found = true;
		}

		l_it++;
	}

}

s_uuid PlayerDisplay::getNewOverlayUuid()
{
	m_overlayUuidCounter++;

	return m_overlayUuidCounter;
}