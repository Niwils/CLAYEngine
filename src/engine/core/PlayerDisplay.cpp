/**
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

PlayerDisplay::PlayerDisplay(IOsalSys *_pOsalSys, PlayerSettings *_pPlayerSettings)
: m_pOsalSys(_pOsalSys)
, m_pPlayerSettings(_pPlayerSettings)
, m_displayMode()
, m_pCamera(nullptr)
{
}

PlayerDisplay::~PlayerDisplay()
{
}

s_errorReturn PlayerDisplay::createWindow()
{
	s_playerWindowWidth l_width = m_pPlayerSettings->getDisplayWidth();

	s_playerWindowWidth l_height = m_pPlayerSettings->getDisplayHeight();

	s_errorReturn l_ret = m_pOsalSys->createNewWindow(l_width, l_height);

	return l_ret;
}

void PlayerDisplay::setModel(IGameModel *_model)
{
	m_pPlayerCompany = _model;
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
			// TODO	
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
	m_pCamera = new PlayerCamera(m_pOsalSys, m_pPlayerSettings, m_pPlayerCompany);
	m_pOsalSys->setupBackgroundColor(0x000000FF);
	m_pCamera->initializeCamera();
	m_displayMode = ePlayerDisplayMode_InGame;
}