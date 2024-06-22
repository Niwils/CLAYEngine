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
#include <PlayerCamera.h>
#include <PlayerActions.h>
#include <PlayerKeyboardRoute.h>
#include <IPlayerDisplayInterface.h>

#include <IOverlayInterface.h>
#include <ObjList.h>
#include <MainGameBar.h>

class PlayerDisplay : public IPlayerDisplayInterface
{
public:
	PlayerDisplay(IOsalSys *_pOsalSys, IRenderer *_pRenderer, PlayerSettings *_pPlayerSettings);
	~PlayerDisplay();

	s_errorReturn createWindow();

	void setModel(IGameModel *_model);

	void setController(IGameController *_controller);

	void parseInputs();
	void moveCamera();
	void rotateCamera(eGeographyDefinition _cameraOrientation);
	void update();

	void switchToMainMenu();

	void switchToGameCamera();

	bool gameQuitRequested();

	void createOverlay(IOverlayInterface *_pDisplay);

    void removeOverlay(s_uuid _uuid);


private:
	void parseEvent();
	void parseWindowEvent();
	void changePlayerFOV();
	
	ePlayerActions parseKeyToAction(eKeyboardKeys _key);
	ePlayerActions parseMouseKeyToAction(eMouseKeys _key);

	void processPlayerAction(ePlayerActions _action);

	void processClick();
	

	IOsalSys *m_pOsalSys;
	IRenderer *m_pRenderer;
	PlayerSettings *m_pPlayerSettings;

	s_coord2d m_cameraCoords; // 2D coordinates of the tile at center location of the camera
	eCameraOrientationDefinition m_cameraOrientation;

	// Model: The player's company.
	IGameModel *m_pPlayerCompany;

	// Controller: The game controller.
	IGameController *m_pController;

	enum ePlayerDisplayMode
	{
		ePlayerDisplayMode_MainMenu,
		ePlayerDisplayMode_InGame,
		ePlayerDisplayMode_Max
	};

	ePlayerDisplayMode m_displayMode;

	PlayerCamera *m_pCamera;

	bool m_gameQuitRequested;

	ISprite *m_pOverlaySprite;
	ISpriteWindow *m_pOverlaySpriteWindow;

	s_uuid m_overlayUuidCounter;
	std::vector<IOverlayInterface *> *m_pOverlayVector;

	s_coord2d m_mouseCoordinates;

};

#endif /* End _ENGINE_CORE_PLAYERDISPLAY_H */
;

