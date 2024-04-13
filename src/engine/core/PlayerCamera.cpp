/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/PlayerCamera.cpp
 *
 * \brief The view object of the MVC model.
 */

/*
 * CHANGELOG:
 * 29/03/2024: File creation (NG)
 */

#include <PlayerCamera.h>

PlayerCamera::PlayerCamera(IOsalSys *_osalSys, PlayerSettings *_playerSettings, IGameModel *_model)
: m_pOsalSys(nullptr)
, m_pPlayerSettings(nullptr)
, m_pGameModel(nullptr)
, m_cameraZoom(c_zoomMax) // game starts with an overview of the map (1:32 scaling ratio)
, m_cameraCoords()
, m_cameraOrientation(eCameraOrientationDefinition_NorthWest)
{
	// TODO assert non-null pointers
	m_pOsalSys = _osalSys;
	m_pPlayerSettings = _playerSettings;
	m_pGameModel = _model;
}

PlayerCamera::~PlayerCamera()
{

}

void PlayerCamera::moveCameraOrientation(eCameraOrientationDefinition _orientation)
{
	m_cameraOrientation = _orientation;
}

void PlayerCamera::moveCameraTranslation(s_coord2d _newCenter)
{
	m_cameraCoords = _newCenter;
}

void PlayerCamera::moveCameraLeft()
{
	s_coord2d l_futureCoordsCameraRef;

	l_futureCoordsCameraRef.x = m_cameraCoords.x - c_cameraTranslationStep;
	l_futureCoordsCameraRef.y = m_cameraCoords.y;

	s_coord2d l_futureCoordsGameRef = this->transformFromCameraRefToModelRef(l_futureCoordsCameraRef);

	if((l_futureCoordsGameRef.x>=0)
		&& (l_futureCoordsGameRef.x<=m_pGameModel->getMapWidth())
		&& (l_futureCoordsGameRef.x>=0)
		&& (l_futureCoordsGameRef.y<=m_pGameModel->getMapWidth())
	)
	{
		m_cameraCoords = l_futureCoordsCameraRef;
	}
	else
	{
		// Do nothing.
	}
}

void PlayerCamera::moveCameraRight()
{
	s_coord2d l_futureCoordsCameraRef;

	l_futureCoordsCameraRef.x = m_cameraCoords.x + c_cameraTranslationStep;
	l_futureCoordsCameraRef.y = m_cameraCoords.y;

	s_coord2d l_futureCoordsGameRef = this->transformFromCameraRefToModelRef(l_futureCoordsCameraRef);

	if((l_futureCoordsGameRef.x>=0)
		&& (l_futureCoordsGameRef.x<=m_pGameModel->getMapWidth())
		&& (l_futureCoordsGameRef.x>=0)
		&& (l_futureCoordsGameRef.y<=m_pGameModel->getMapWidth())
	)
	{
		m_cameraCoords = l_futureCoordsCameraRef;
	}
	else
	{
		// Do nothing.
	}
}

void PlayerCamera::moveCameraUpwards()
{
	s_coord2d l_futureCoordsCameraRef;

	l_futureCoordsCameraRef.x = m_cameraCoords.x;
	l_futureCoordsCameraRef.y = m_cameraCoords.y + c_cameraTranslationStep;

	s_coord2d l_futureCoordsGameRef = this->transformFromCameraRefToModelRef(l_futureCoordsCameraRef);

	if((l_futureCoordsGameRef.x>=0)
		&& (l_futureCoordsGameRef.x<=m_pGameModel->getMapWidth())
		&& (l_futureCoordsGameRef.x>=0)
		&& (l_futureCoordsGameRef.y<=m_pGameModel->getMapWidth())
	)
	{
		m_cameraCoords = l_futureCoordsCameraRef;
	}
	else
	{
		// Do nothing.
	}
}

void PlayerCamera::moveCameraDownwards()
{
	s_coord2d l_futureCoordsCameraRef;

	l_futureCoordsCameraRef.x = m_cameraCoords.x;
	l_futureCoordsCameraRef.y = m_cameraCoords.y - c_cameraTranslationStep;

	s_coord2d l_futureCoordsGameRef = this->transformFromCameraRefToModelRef(l_futureCoordsCameraRef);

	if((l_futureCoordsGameRef.x>=0)
		&& (l_futureCoordsGameRef.x<=m_pGameModel->getMapWidth())
		&& (l_futureCoordsGameRef.x>=0)
		&& (l_futureCoordsGameRef.y<=m_pGameModel->getMapWidth())
	)
	{
		m_cameraCoords = l_futureCoordsCameraRef;
	}
	else
	{
		// Do nothing.
	}
}

void PlayerCamera::unzoomCamera()
{
	if(0<m_cameraZoom)
	{
		m_cameraZoom -= c_zoomIncrement;
	}
	else
	{
		m_cameraZoom = 0;
	}
}

void PlayerCamera::zoomCamera()
{
	if(c_zoomMax>m_cameraZoom)
	{
		m_cameraZoom += c_zoomIncrement;
	}
	else
	{
		m_cameraZoom = c_zoomMax;
	}
}

s_pixelsPerTile PlayerCamera::getSpritesSize()
{
	if(0<m_cameraZoom)
	{
		return c_pixelsPerTile/m_cameraZoom;
	}
	else
	{
		return c_pixelsPerTile;
	}
}

void PlayerCamera::initializeCamera()
{
	s_pixelsPerTile l_increment = this->getSpritesSize();

	s_coord2d l_icpt;

	for(l_icpt.y = 0; (m_pPlayerSettings->getDisplayHeight() > l_icpt.y); l_icpt.y += l_increment)
	{
		for(l_icpt.x= 0; (m_pPlayerSettings->getDisplayWidth() > l_icpt.x); l_icpt.x += l_increment)
		{
			s_coord2d l_tileCoords = transformFromWindowRefToModelRef(l_icpt);

			if((l_tileCoords.x>=0)
				&& (l_tileCoords.x<=m_pGameModel->getMapWidth())
				&& (l_tileCoords.x>=0)
				&& (l_tileCoords.y<=m_pGameModel->getMapWidth())
			)
			{
				ITile *l_pTile = nullptr;
				l_pTile = m_pGameModel->getTile(l_tileCoords);
				m_pOsalSys->displaySprite(l_pTile->getSprite(), l_tileCoords, this->getSpritesSize());
			}
			else
			{
				// Do nothing.
			}
		}
	}
}

s_coord2d PlayerCamera::transformFromWindowRefToModelRef(s_coord2d _windowCoordinates)
{
	// translation from the window referential to the camera referential.
	s_coord2d l_cameraCoordinates;
	l_cameraCoordinates.x = _windowCoordinates.x - 0.5*m_pPlayerSettings->getDisplayWidth();
	l_cameraCoordinates.y = _windowCoordinates.y - 0.5*m_pPlayerSettings->getDisplayHeight();

	// translation from the camera referential to the virtual referential.
	s_coord2d l_virtualCoordinates;

	l_virtualCoordinates.x = l_cameraCoordinates.x + m_cameraCoords.x;
	l_virtualCoordinates.y = l_cameraCoordinates.y + m_cameraCoords.y;

	s_coord2d l_gameCoordinates;
		l_gameCoordinates.x = ct_rotationCameraToGameCoeffs[m_cameraOrientation][0]*l_virtualCoordinates.x
						+ ct_rotationCameraToGameCoeffs[m_cameraOrientation][1]*l_virtualCoordinates.y;

		l_gameCoordinates.y = ct_rotationCameraToGameCoeffs[m_cameraOrientation][2]*l_virtualCoordinates.x
						+ ct_rotationCameraToGameCoeffs[m_cameraOrientation][3]*l_virtualCoordinates.y;

		// moving the coordinates to the model referential.
		l_gameCoordinates.x += 0.5*m_pGameModel->getMapWidth();
		l_gameCoordinates.y += 0.5*m_pGameModel->getMapHeight();
	return l_gameCoordinates;

}

s_coord2d PlayerCamera::transformFromCameraRefToModelRef(s_coord2d _cameraCoordinates)
{
	// translation from the camera referential to the virtual referential.
	s_coord2d l_virtualCoordinates;

	l_virtualCoordinates.x = _cameraCoordinates.x + m_cameraCoords.x;
	l_virtualCoordinates.y = _cameraCoordinates.y + m_cameraCoords.y;

	s_coord2d l_gameCoordinates;
		l_gameCoordinates.x = ct_rotationCameraToGameCoeffs[m_cameraOrientation][0]*l_virtualCoordinates.x
						+ ct_rotationCameraToGameCoeffs[m_cameraOrientation][1]*l_virtualCoordinates.y;

		l_gameCoordinates.y = ct_rotationCameraToGameCoeffs[m_cameraOrientation][2]*l_virtualCoordinates.x
						+ ct_rotationCameraToGameCoeffs[m_cameraOrientation][3]*l_virtualCoordinates.y;

		// moving the coordinates to the model referential.
		l_gameCoordinates.x += 0.5*m_pGameModel->getMapWidth();
		l_gameCoordinates.y += 0.5*m_pGameModel->getMapHeight();
	return l_gameCoordinates;

}

s_coord2d PlayerCamera::transformFromModelRefToWindowRef(s_coord2d _modelCoordinates)
{
		// rotation from the game referential to the virtual referential
	s_coord2d l_gameCoordinates;
	l_gameCoordinates.x = _modelCoordinates.x - (0.5*m_pGameModel->getMapWidth());
	l_gameCoordinates.y = _modelCoordinates.y - (0.5*m_pGameModel->getMapHeight());

	s_coord2d l_virtualCoordinates;
	l_virtualCoordinates.x = ct_rotationGameToCameraCoeffs[m_cameraOrientation][0]*l_gameCoordinates.x
					+ ct_rotationGameToCameraCoeffs[m_cameraOrientation][1]*l_gameCoordinates.y;

	l_virtualCoordinates.y = ct_rotationGameToCameraCoeffs[m_cameraOrientation][2]*l_gameCoordinates.x
						+ ct_rotationGameToCameraCoeffs[m_cameraOrientation][3]*l_gameCoordinates.y;

	// translation from the virtual referential to the camera referential.
	s_coord2d l_cameraCoordinates;

	l_cameraCoordinates.x = l_virtualCoordinates.x - m_cameraCoords.x;
	l_cameraCoordinates.y = l_virtualCoordinates.y - m_cameraCoords.y;

	// translation from the camera referential to the window referential.
	s_coord2d l_windowCoordinates;
	l_windowCoordinates.x = l_cameraCoordinates.x + 0.5*m_pPlayerSettings->getDisplayWidth();
	l_windowCoordinates.y = l_cameraCoordinates.y + 0.5*m_pPlayerSettings->getDisplayHeight();

	return l_windowCoordinates;
}
