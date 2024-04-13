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

void PlayerDisplay::update()
{

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
