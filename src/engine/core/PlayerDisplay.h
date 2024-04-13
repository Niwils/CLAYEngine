/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/PlayerDisplay.h
 *
 * \brief The view object of the MVC model.
 */

/*
 * CHANGELOG:
 * 16/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_PLAYERDISPLAY_H
#define _ENGINE_CORE_PLAYERDISPLAY_H

// #include <Company.h>
// #include <IDisplay.h>
#include <Types.h>
#include <GeographyDefinitions.h>
#include <OsalSys.h>
#include <PlayerSettings.h>
#include <IGameModel.h>
#include <IGameController.h>

class PlayerDisplay // : public IDisplay
{
public:
	PlayerDisplay(IOsalSys *_pOsalSys, PlayerSettings *_pPlayerSettings);
	~PlayerDisplay();

	s_errorReturn createWindow();

	void setModel(IGameModel *_model);

	void setController(IGameController *_controller);

	void moveCamera();
	void rotateCamera(eGeographyDefinition _cameraOrientation);
	void update();


private:
	void parseEvent();
	void parseWindowEvent();
	void changePlayerFOV();

	IOsalSys *m_pOsalSys;
	PlayerSettings *m_pPlayerSettings;

	s_coord2d m_cameraCoords; // 2D coordinates of the tile at center location of the camera
	eCameraOrientationDefinition m_cameraOrientation;

	// Model: The player's company.
	IGameModel *m_pPlayerCompany;

	// Controller: The game controller.
	IGameController *m_pController;

};

#endif /* End _ENGINE_CORE_PLAYERDISPLAY_H */
;

