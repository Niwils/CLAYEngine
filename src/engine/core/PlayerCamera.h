/*!
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/PlayerCamera.h
 *
 * \brief The view object of the MVC model.
 */

/*
 * CHANGELOG:
 * 29/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_PLAYERCAMERA_H
#define _ENGINE_CORE_PLAYERCAMERA_H

#include <Types.h>
#include <GeographyDefinitions.h>
#include <OsalSys.h>
#include <PlayerSettings.h>
#include <IGameModel.h>
#include <IGameController.h>

/*!
 * 	\brief The PlayerCamera class is in charge of rendering the model state within the PlayerDisplay.
 *
 *  A quick overview regarding the referential within the game
 *  (this comment will be subject to a future REFERENTIALS.md)
 *
 *  The model of the player company is a 2D array of tiles, with (0;0)) the tile indicating the
 *  top corner when facing the camera in a North-west orientation. Due to the isometric 3D of the game
 *  a 30° rotation between where the player clicks and the associated tile shall be performed.
 *
 *  When locating the tile from a pixel camera location, the following operations shall be performed:
 *  (assuming the camera facing north-west. Development shall consider the four corners)
 *
 *  1/ SDL returns the click position with (0,0) as the upper left corner position of the screen.
 *  Hence, we first translate the click position from the center of the camera:
 *
 *  |x_cam| = | 1 0 -0.5*(m_playerSettings->getDisplayWidth()  | * | x_sdl |
 *  |y_cam|   | 0 1 -0.5*(m_playerSettings->getDisplayHeight() |   | y_sdl |
 *
 *  2/ Then we locate the click position within a "virtual screen" representing the complete map
 *  expressed in pixels.
 *
 *  |x_virtual| = | 1 0 m_cameraCoords.x  | * | x_cam |
 *  |y_virtual|   | 0 1 m_cameraCoords.y  |   | y_cam |
 *
 *  3/ Then we locate the click position within the tile referential of the model
 *  |x_model| = 1/PIXELS_PER_TILE*| cos(30°) -sin(30°) | * |x_virtual|
 *  |y_model| 					  | sin(30°) cos(30°)  |   |y_virtual|
 *
 * With cos(30°) and sin(30°) operated as a LUT to keep the computating low.
 */

class PlayerCamera
{
public:
	/*!
	* \brief The PlayerCamera constructor.
	*
	* \param _pOsalSys Pointer to the IOsalSys
	* \param _pPlayerSettings Pointer to the player settings container.
	* \param _pModel Pointer to the in-game model.
	* \param _pMouseOverlay Pointer to the mouse overlay Sprite Window.
	*/
	PlayerCamera(IOsalSys *_pOsalSys, PlayerSettings *_pPlayerSettings, IGameModel *_pModel, ISpriteWindow *_pMouseOverlay);

	/*!
	* \brief The destructor for PlayerCamera.
	*/
	~PlayerCamera();

	/*!
	* \brief Set the PlayerCamera to the new eCameraOrientationDefinition.
	*
	* \todo implement this in alpha2.0
	* \param _orientation new camera orientation, requested by the player.
	*/
	void moveCameraOrientation(eCameraOrientationDefinition _orientation);

	/*!
	* \brief Set the new PlayerCamera center, from the virtual referential center.
	*
	* \param _newCenter new camera center position, from the virtual referential center
	*/
	void moveCameraTranslation(s_coord2d _newCenter);

	/*!
	* \brief Translate the camera of c_cameraTranslationStep to the left.
	*/
	void moveCameraLeft();

	/*!
	* \brief Translate the camera of c_cameraTranslationStep to the right.
	*/
	void moveCameraRight();

	/*!
	* \brief Translate the camera of c_cameraTranslationStep to the top.
	*/
	void moveCameraUpwards();

	/*!
	* \brief Translate the camera of c_cameraTranslationStep to the bottom.
	*/
	void moveCameraDownwards();

	/*!
	* \brief Unzoom the camera.
	*/
	void unzoomCamera();

	/*!
	* \brief Zoom the camera.
	*/
	void zoomCamera();

	/*!
	* \brief Return the tile width, from the camera referential standpoint. Zoom ratio is included.
	*
	* \return A tile width, in pixels.
	*/
	s_nbPixels getCamSpritesWidth();

	/*!
	* \brief Return the tile height, from the camera referential standpoint. Zoom ratio is included.
	*
	* \return A tile height, in pixels.
	*/
	s_nbPixels getCamSpritesHeight();

	/*!
	* \brief Return the tile width, from the map referential standpoint. Zoom ratio is included.
	*
	* \return A tile width, in pixels.
	*/
	s_nbPixels getMapSpritesWidth();

	/*!
	* \brief Return the tile height, from the map referential standpoint. Zoom ratio is included.
	*
	* \return A tile height, in pixels.
	*/
	s_nbPixels getMapSpritesHeight();

	/*!
	* \brief Call for map rendering. The renderer will be filled with the model content for the whole screen.
	* Remark: it is recommended to call this function before rendering overlays.
	*/
	void refreshCamera();

	/*!
	* \brief Return if the new camera center coordinates is within the map or not.
	* \return True if within the map, false otherwise.
	*/
	bool newCameraCoordsWithinMap(s_coord2d _newCoords);

	/*!
	* \brief Set the mouse pointer coordinates, for mouse overlay rendering.
	*/
	void setMousePointerCoords(s_coord2d _mouseCoords);

protected:

	/*!
	* \brief Calculates the coordinates from the Window to the Model referential
	* \param _windowCoordinates The window coordinates.
	* \return The model coordinates.
	*/
	s_coord2d transformFromWindowRefToModelRef(s_coord2d _windowCoordinates);

	/*!
	* \brief Calculates the coordinates from the Camera to the Model referential
	* \param _cameraCoordinates The camera coordinates.
	* \return The model coordinates.
	*/
	s_coord2d transformFromCameraRefToModelRef(s_coord2d _cameraCoordinates);

	/*!
	* \brief Calculates the coordinates from the Virtual to the Model referential
	* \param _virtualCoordinates The Virtual coordinates.
	* \return The model coordinates.
	*/
	s_coord2d transformFromVirtualRefToModelRef(s_coord2d _virtualCoordinates);

	/*!
	* \brief Calculates the coordinates from the Model to the Window referential
	* \param _gameCoordinates The in-game model coordinates.
	* \return The window coordinates.
	*/
	s_coord2d transformFromModelRefToWindowRef(s_coord2d _gameCoordinates);

	/*!
	* \brief Place the mouse overlay over the tile where the mouse points to.
	* \param _mouseCoordinates The mouse coordinates coordinates, within the Window referential.
	*/
	void placeOverlay(s_coord2d _mouseCoordinates);

private:
	/*!
	* \brief Pointer the OsalSys OSAL abstraction object.
	*/
	IOsalSys *m_pOsalSys;

	/*!
	* \brief Pointer the player settings container.
	*/
	PlayerSettings *m_pPlayerSettings;

	/*!
	* \brief Pointer the in-game model.
	*/
	IGameModel *m_pGameModel;

	/*!
	* \brief The camera zoom ratio.
	*/
	s_zoomRatio m_cameraZoom;

	/*!
	* \brief Zoom increment per zoom incrementation request from the player.
	*/
	const s_zoomRatio c_zoomIncrement = 2;

	/*!
	* \brief Maximum zoom ratio. 1:8 scale is max.
	*/
	const s_zoomRatio c_zoomMax = 8;

	/*!
	* \brief Tile width, within the camera referential.
	*/
	const s_nbPixels c_pixelsWidePerTile = 424U;

	/*!
	* \brief Tile height, within the camera referential.
	*/
	const s_nbPixels c_pixelsHighPerTile = 212U;

	/*!
	* \brief Tile width, within the game referential.
	*/
	const s_nbPixels c_pixelsWideInModelRef = 270;

	/*!
	* \brief The camera center coordinates, from the virtual referential center.
	*/
	s_coord2d m_cameraCoords;

	/*!
	* \brief The mouse overlay center coordinates, in the Model referential.
	*/
	s_coord2d m_overlayCoords;

	/*!
	* \brief Used to display the overlay only when the player cursor in over the map. True if this the case.
	*/
	bool m_overlayIsShown;

	/*!
	* \brief Virtual map width
	*/
	s_nbPixels m_virtualMapWidth;

	/*!
	* \brief Virtual map height
	*/
	s_nbPixels m_virtualMapHeight;

	/*!
	* \brief Number of pixels for each camera translation (on X and Y axis)
	*/
	const s_coord c_cameraTranslationStep = 16; // Camera translation step

	/*!
	* \brief Camera orientation
	* \todo alpha2.0 will provide more than one point of view.
	*/
	eCameraOrientationDefinition m_cameraOrientation;

	/*!
	* \brief Pointer to the mouse overlay sprite.
	*/
	ISpriteWindow *m_pOverlaySprite;

	/*!
	* \brief Coefficients for rotation matrix (virtual-to-game referentials), repartited as below:
	* | [0] [1] |
	* | [2] [3] |
	*/
	const s_rotationCoeff ct_rotationCameraToGameCoeffs[eCameraOrientationDefinition_Max][4]  =
	{
			{0.707, 0.707, -0.707, 0.707}, // eCameraOrientationDefinition_NorthWest (+45)°
			{0.866, 0.5, -0.5, 0.866}, // eCameraOrientationDefinition_NorthEast (-30°)
			{-0.866, -0.5, 0.5, -0.866}, // eCameraOrientationDefinition_SouthWest (+150°)
			{-0.866, 0.5, -0.5, -0.866} // eCameraOrientationDefinition_SouthEast (-150°)
	};

	/*!
	* \brief Coefficients for rotation matrix (game-to-virtual referentials), repartited as below:
	* | [0] [1] |
	* | [2] [3] |
	*/
	const s_rotationCoeff ct_rotationGameToCameraCoeffs[eCameraOrientationDefinition_Max][4]  =
	{
			{0.866, 0.5, -0.5, 0.866}, // eCameraOrientationDefinition_NorthWest (-30°s)
			{0.866, -0.5, 0.5, 0.866}, // eCameraOrientationDefinition_NorthEast (+30°)
			{-0.866, 0.5, -0.5, -0.866}, // eCameraOrientationDefinition_SouthWest (-150°)
			{-0.866, -0.5, 0.5, -0.866} // eCameraOrientationDefinition_SouthEast (+150°)
	};
};

#endif /* End _ENGINE_CORE_PLAYERCAMERA_H */
