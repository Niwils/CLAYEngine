/*
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

/**
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
	PlayerCamera(IOsalSys *_osalSys, PlayerSettings *_playerSettings, IGameModel *_model);

	~PlayerCamera();

	void moveCameraOrientation(eCameraOrientationDefinition _orientation);

	void moveCameraTranslation(s_coord2d _newCenter);

	void moveCameraLeft();

	void moveCameraRight();

	void moveCameraUpwards();

	void moveCameraDownwards();

	void unzoomCamera();

	void zoomCamera();

	s_pixelsPerTile getSpritesSize();

	void initializeCamera();

protected:

	s_coord2d transformFromWindowRefToModelRef(s_coord2d _windowCoordinates);

	s_coord2d transformFromCameraRefToModelRef(s_coord2d _windowCoordinates);

	s_coord2d transformFromModelRefToWindowRef(s_coord2d _gameCoordinates);

private:
	IOsalSys *m_pOsalSys;
	PlayerSettings *m_pPlayerSettings;
	IGameModel *m_pGameModel;

	s_zoomRatio m_cameraZoom;

	const s_zoomRatio c_zoomIncrement = 8; // Zoom increment
	const s_zoomRatio c_zoomMax = 32; // 1:32 scale is max.

	const s_pixelsPerTile c_pixelsPerTile = 256; // 256 pixels at full scale zoom?

	// Coordinates within the "virtual" referential.
	s_coord2d m_cameraCoords; // 2D coordinates of the tile at center location of the camera

	const s_coord c_cameraTranslationStep = 16; // Camera translation step

	eCameraOrientationDefinition m_cameraOrientation;

	// Coefficients for rotation matrix, repartited as below:
	// | [0] [1] |
	// | [2] [3] |
	const s_rotationCoeff ct_rotationCameraToGameCoeffs[eCameraOrientationDefinition_Max][4]  =
	{
			{0.866, -0.5, 0.5, 0.866}, // eCameraOrientationDefinition_NorthWest (+30)°
			{0.866, 0.5, -0.5, 0.866}, // eCameraOrientationDefinition_NorthEast (-30°)
			{-0.866, -0.5, 0.5, -0.866}, // eCameraOrientationDefinition_SouthWest (+150°)
			{-0.866, 0.5, -0.5, -0.866} // eCameraOrientationDefinition_SouthEast (-150°)
	};

	const s_rotationCoeff ct_rotationGameToCameraCoeffs[eCameraOrientationDefinition_Max][4]  =
	{
			{0.866, 0.5, -0.5, 0.866}, // eCameraOrientationDefinition_NorthWest (-30°s)
			{0.866, -0.5, 0.5, 0.866}, // eCameraOrientationDefinition_NorthEast (+30°)
			{-0.866, 0.5, -0.5, -0.866}, // eCameraOrientationDefinition_SouthWest (-150°)
			{-0.866, -0.5, 0.5, -0.866} // eCameraOrientationDefinition_SouthEast (+150°)
	};
};

#endif /* End _ENGINE_CORE_PLAYERCAMERA_H */
