/**
 * The CLAYEngine project.
 *
 * @file /src/engine/core/PlayerSettings.cpp
 *
 * @brief The player control, audio and display settings are located here.
 */

/*
 * CHANGELOG:
 * 20/03/2024: File creation (NG)
 */

#include <PlayerSettings.h>

PlayerSettings::PlayerSettings()
: m_playerDisplayResolution(ePlayerSettingsDisplayResolution_None)
, m_playerDisplayIsFullscreen(false)
{

}

PlayerSettings::~PlayerSettings()
{

}

ePlayerSettingsDisplayResolution PlayerSettings::getPlayerDisplayResolution()
{
	return m_playerDisplayResolution;
}

void PlayerSettings::setPlayerDisplayResolution(ePlayerSettingsDisplayResolution _playerResolution)
{
	m_playerDisplayResolution = _playerResolution;
}

bool PlayerSettings::isPlayerDisplayFullscreen()
{
	return m_playerDisplayIsFullscreen;
}

void PlayerSettings::setPlayerDisplayFullscreen(s_isFullscreen _isFullscreen)
{
	m_playerDisplayIsFullscreen = _isFullscreen;
}

void PlayerSettings::setCameraTravellingSpeed(s_nbPixels _travellingSpeed)
{
	m_cameraTravellingSpeed = _travellingSpeed;
}

s_playerWindowWidth PlayerSettings::getDisplayWidth()
{
	s_playerWindowWidth l_return;

	switch(m_playerDisplayResolution)
	{
		case ePlayerSettingsDisplayResolution_640x480:
			l_return = 640;
			break;

		case ePlayerSettingsDisplayResolution_1024x768:
			l_return = 1024;
			break;

		default:
			// TODO raise error.
			break;
	}

	return l_return;
}

s_playerWindowWidth PlayerSettings::getDisplayHeight()
{
	s_playerWindowWidth l_return;

	switch(m_playerDisplayResolution)
	{
		case ePlayerSettingsDisplayResolution_640x480:
			l_return = 480;
			break;

		case ePlayerSettingsDisplayResolution_1024x768:
			l_return = 768;
			break;

		default:
			// TODO raise error.
			break;
	}

	return l_return;
}


s_nbPixels PlayerSettings::getCameraTravellingSpeed()
{
	return m_cameraTravellingSpeed;
}
