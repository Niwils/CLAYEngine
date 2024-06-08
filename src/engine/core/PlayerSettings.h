/**
 * The CLAYEngine project.
 *
 * @file /src/engine/core/PlayerSettings.h
 *
 * @brief The player control, audio and display setttings are located here.
 */

/*
 * CHANGELOG:
 * 20/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_PLAYERSETTINGS_H
#define _ENGINE_CORE_PLAYERSETTINGS_H

#include <Types.h>

class PlayerSettings
{
public:
	PlayerSettings();
	~PlayerSettings();

	ePlayerSettingsDisplayResolution getPlayerDisplayResolution();

	void setPlayerDisplayResolution(ePlayerSettingsDisplayResolution _playerResolution);

	bool isPlayerDisplayFullscreen();

	void setPlayerDisplayFullscreen(s_isFullscreen _isFullscreen);

	void setCameraTravellingSpeed(s_nbPixels _travellingSpeed);

	s_playerWindowWidth getDisplayWidth();

	s_playerWindowHeight getDisplayHeight();

	s_nbPixels getCameraTravellingSpeed();

private:
	ePlayerSettingsDisplayResolution m_playerDisplayResolution;

	s_isFullscreen m_playerDisplayIsFullscreen;

	s_nbPixels m_cameraTravellingSpeed;

};
#endif /* End _ENGINE_CORE_PLAYERSETTINGS_H */
