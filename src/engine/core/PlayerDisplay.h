/*!
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
#include <MenuSpritesContainer.h>

/*!
* \class PlayerDisplay
* \brief The PlayerDisplay class is the viewer of the MVC model.
*
* The PlayerDisplay class is in charge of:
* - at the request from the main loop, request all the player inputs fromIOsalSys 
* - parse and proceed the player inputs either on the display itself or on the controller
* - at the request from the main loop, request the rendering of the overlays and the associated player camera (if in-game).
*
* The PlayerDisplay behaviour depends on its current state:
* - MainMenu: PlayerDisplay will not use or route player inputs to the associated PlayerCamera, as only the overlays are shown.
* - InGame: PlayerDisplay will route the player inputs to the in-game content: at first to overlays if required, otherwise, to the PlayerCamera.  
*/
class PlayerDisplay : public IPlayerDisplayInterface
{
public:
	/*!
	* \brief Instantiates a power display.
	* \param _pOsalSys Pointer to the IOsalSys
	* \param _pRenderer Pointer to the display renderer
	* \param _pPlayerSettings Pointer to the player settings container.
	*/
	PlayerDisplay(IOsalSys *_pOsalSys, IRenderer *_pRenderer, PlayerSettings *_pPlayerSettings);

	/*!
	* \brief The PlayerDisplay destructor
	*/
	~PlayerDisplay();

	/*!
	* \brief Create and renders a new window, with the resolution given in the associated PlayerSettings parameters.
	*
	* \return 0 if no error has been raised. TODO otherwise.
	*/
	s_errorReturn createWindow();

	/*!
	* \brief IGameModel setter.
	* \param _pModel Pointer to the IGameModel used for this game.
	*/
	void setModel(IGameModel *_pModel);

	/*!
	* \brief IGameController setter.
	* \param _pController Pointer to the IGameModel used for this game.
	*/
	void setController(IGameController *_pController);

	/*!
	* \brief Called by the main loop, request the player inputs 
	*/
	void parseInputs();

	/*!
	* \todo Implement multiple angle POV (alpha 2.0)
	*/
	void rotateCamera(eGeographyDefinition _cameraOrientation);

	/*!
	* \brief Called by the main loop, it updates the window content.
	*/
	void update();

	/*!
	* \brief Change the PlayerDisplay state from In-game to MainMenu.
	*/
	void switchToMainMenu();

	/*!
	* \brief Change the PlayerDisplay state from MainMenu to In-game.
	*/
	void switchToGameCamera();

	/*!
	* \brief Returns if the player has requested to quit the game.
	* \return true if player has requested to quit the game, false otherwise.
	*/
	bool gameQuitRequested();

	void createOverlay(IOverlayInterface *_pDisplay);

    void removeOverlay(s_uuid _uuid);

	s_uuid getNewOverlayUuid();

private:
	/*!
	* \todo 
	*/
	void parseEvent();

	/*!
	* \todo 
	*/
	void parseWindowEvent();

	/*!
	* \todo 
	*/
	void changePlayerFOV();
	
	/*!
	* \brief Retrieves the binded player action from a key.
	* \param _key Key pressed by the player
	* \return The player action binded with the given pressed key.
	*/
	ePlayerActions parseKeyToAction(eKeyboardKeys _key);

	/*!
	* \brief Retrieves the binded player action from a mouse action.
	* \param _key Mouse key pressed by the player
	* \return The player action binded with the given mouse action.
	*/
	ePlayerActions parseMouseKeyToAction(eMouseKeys _key);

	/*!
	* \brief Proceeds the player action within the display, or transmit it to the associated IGameController.
	*
	* \param _action The player action.
	*/
	void processPlayerAction(ePlayerActions _action);

	/*!
	* \brief When a player action is a click, process the coordinates and transmits this action to:
	* - If within the area, the associated overlay.
	* - If in an InGame state, the associated PlayerCamera.
	*/
	void processClick();
	
	/*!
	* \brief A pointer to the IOsalSys of the game, i.e. the access to low-level resources such as graphic and sound cards, OS syscalls, mouse and keyboard...
	*/
	IOsalSys *m_pOsalSys;

	/*!
	* \brief A pointer to the IRenderer of the game, a VRAM buffer.
	*/
	IRenderer *m_pRenderer;

	/*!
	* \brief A pointer to the player settings container.
	*/
	PlayerSettings *m_pPlayerSettings;

	/*!
	* \brief A pointer to the in-game model.
	*/
	IGameModel *m_pPlayerCompany;

	/*!
	* \brief A pointer to the in-game controller.
	*/
	IGameController *m_pController;

	/*!
	* \brief The definition of PlayerDisplay modes
	*/
	enum ePlayerDisplayMode
	{
		ePlayerDisplayMode_MainMenu, /*!< Display is in Main Menu mode */
		ePlayerDisplayMode_InGame, /*!< Display is in in-game mode, i.e. with camera rendering */
		ePlayerDisplayMode_Max /*!< Enum upper bound */
	};

	/*!
	* \brief The current display mode.
	*/
	ePlayerDisplayMode m_displayMode;

	/*!
	* \brief The pointer to the player camera, if in InGame mode.
	*/
	PlayerCamera *m_pCamera;

	/*!
	* \brief If true, indicates the player has requested to quit the game, or at least to close the window.
	*/
	bool m_gameQuitRequested;

	/*!
	* \brief The pointer to the player camera overlay sprite, i.e. mouse tracker on the PlayerCamera
	* \todo move this in the PlayerCamera for clarity.
	*/
	ISprite *m_pOverlaySprite;

	/*!
	* \brief The pointer to the player camera overlay SpriteWindow (i.e. rendering), for m_pOverlaySprite
	* \todo move this in the PlayerCamera for clarity.
	*/
	ISpriteWindow *m_pOverlaySpriteWindow;

	/*!
	* \brief The counter for overlay UUIDs, as the overlay UUID is assigned by the PlayerDisplay.
	*/
	s_uuid m_overlayUuidCounter;

	/*!
	* \brief The vector of OverlayInterface, i.e. all overlays shown on-screen.
	*/
	std::vector<IOverlayInterface *> *m_pOverlayVector;

	/*!
	* \brief The last known player mouse coordinates.
	*/
	s_coord2d m_mouseCoordinates;

	/*!
	* \brief The menu icons container.
	*/
	MenuSpritesContainer *m_pSprites;

};

#endif /* End _ENGINE_CORE_PLAYERDISPLAY_H */
;

