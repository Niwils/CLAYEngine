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
, m_cameraZoom(8U) // TODO: game starts with an overview of the map (1:32 scaling ratio)
, m_cameraCoords()
, m_virtualCenterCoords()
, m_virtualMapWidth(_model->getMapWidth()*424U)
, m_virtualMapHeight(_model->getMapHeight()*212U)
, m_cameraOrientation(eCameraOrientationDefinition_NorthWest)
{
	// TODO assert non-null pointers
	m_pOsalSys = _osalSys;
	m_pPlayerSettings = _playerSettings;
	m_pGameModel = _model;

	m_virtualCenterCoords.x = m_virtualMapWidth/2U;
	m_virtualCenterCoords.y = m_virtualMapHeight/2U;

	//m_cameraCoords.y = m_pPlayerSettings->getDisplayHeight()/2U;
	//m_cameraCoords.x = m_pPlayerSettings->getDisplayWidth()/2U;
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
	if(c_zoomIncrement < m_cameraZoom)
	{
		m_cameraZoom -= c_zoomIncrement;
	}
	else
	{
		m_cameraZoom = 1;
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

s_nbPixels PlayerCamera::getCamSpritesWidth()
{
	if(0<m_cameraZoom)
	{
		return c_pixelsWidePerTile/m_cameraZoom;
	}
	else
	{
		return c_pixelsWidePerTile;
	}
}

s_nbPixels PlayerCamera::getCamSpritesHeight()
{
	if(0<m_cameraZoom)
	{
		return c_pixelsHighPerTile/m_cameraZoom;
	}
	else
	{
		return c_pixelsHighPerTile;
	}
}

s_nbPixels PlayerCamera::getMapSpritesWidth()
{
	if(0<m_cameraZoom)
	{
		return (c_pixelsWidePerTile/m_cameraZoom)/0.707;
	}
	else
	{
		return c_pixelsWidePerTile/0.707;
	}
}

s_nbPixels PlayerCamera::getMapSpritesHeight()
{
	if(0<m_cameraZoom)
	{
		return (c_pixelsHighPerTile/m_cameraZoom)/0.707;
	}
	else
	{
		return c_pixelsHighPerTile/0.707;
	}
}

void PlayerCamera::initializeCamera()
{
	// Increments are divided by two as we are in isometric 3D.
	s_nbPixels l_increment_x = 0.5*(this->getCamSpritesWidth());
	s_nbPixels l_increment_y = 0.5*(this->getCamSpritesHeight());

	s_MapWidth l_mapWidth = m_pGameModel->getMapWidth();
	s_MapHeight l_mapHeight = m_pGameModel->getMapHeight();

	s_coord2d l_icpt;

	m_pOsalSys->clearWindow();

	std::vector<s_bool> *l_tDisplayed = new std::vector<s_bool>(l_mapHeight*l_mapWidth, false);

	for(l_icpt.y = 0; (m_pPlayerSettings->getDisplayHeight() > l_icpt.y); l_icpt.y += l_increment_y)
	{ 
		for(l_icpt.x= 0; (m_pPlayerSettings->getDisplayWidth() > l_icpt.x); l_icpt.x += l_increment_x)
		{
			s_coord2d l_tileCoords = transformFromWindowRefToModelRef(l_icpt);

			// We check if the calculated tile coordinates are within the game.
			// If yes, we request the associated sprite.
			if((l_tileCoords.x>=0)
				&& (l_tileCoords.x<m_pGameModel->getMapWidth())
				&& (l_tileCoords.y>=0)
				&& (l_tileCoords.y<m_pGameModel->getMapHeight())
			)
			{
				if(false == l_tDisplayed->at((l_tileCoords.y*l_mapWidth)+l_tileCoords.x))
				{
					// We calculate the center position of the sprite within the screen
					s_coord2d l_tileInWindowRef = transformFromModelRefToWindowRef(l_tileCoords);
					ITile *l_pTile = nullptr;
					l_pTile = m_pGameModel->getTile(l_tileCoords);
					ISpriteWindow *l_spriteFov = l_pTile->getSpriteWindow();
					l_spriteFov->setupRendering(l_tileInWindowRef, m_cameraZoom,
													m_pPlayerSettings->getDisplayWidth(),
													m_pPlayerSettings->getDisplayHeight()
												);

					m_pOsalSys->displaySprite(l_spriteFov, l_tileInWindowRef, m_cameraZoom);
					l_tDisplayed->at((l_tileCoords.y*l_mapWidth)+l_tileCoords.x) = true;
				}
			}
			else
			{
				// Do nothing.
			}
		}
	}

	delete l_tDisplayed;

	m_pOsalSys->updateWindow();
}

s_coord2d PlayerCamera::transformFromModelRefToWindowRef(s_coord2d _modelCoordinates)
{
	s_coord2d l_cameraCoords;
	// Positionning the model coordinates within the virtual referential
	s_coord2d l_virtualCoords;

	s_nbPixels l_spriteWidth = this->getCamSpritesWidth();
	s_nbPixels l_spriteHeight = this->getCamSpritesHeight();

	s_nbPixels l_spriteHalfWidth = 0.5*l_spriteWidth;
	s_nbPixels l_spriteHalfHeight = 0.5*l_spriteHeight;

	s_nbPixels l_nbMapWidth = m_virtualMapWidth/m_cameraZoom;
	s_nbPixels l_nbMapHeight = m_virtualMapHeight/m_cameraZoom;

	// Virtual coordinates are centered in the full map.
	l_virtualCoords.x = -0.5*l_nbMapWidth + l_spriteHalfWidth + l_spriteHalfWidth*_modelCoordinates.x + l_spriteHalfWidth*_modelCoordinates.y;
	l_virtualCoords.y = -l_spriteHalfHeight*_modelCoordinates.y + l_spriteHalfHeight*_modelCoordinates.x;

	s_coord2d l_cameraCoordinates;

	l_cameraCoordinates.x = l_virtualCoords.x + m_cameraCoords.x;
	l_cameraCoordinates.y = l_virtualCoords.y + m_cameraCoords.y;

	s_coord2d l_windowCoord;

	l_windowCoord.x = l_cameraCoordinates.x+0.5*m_pPlayerSettings->getDisplayWidth();
	l_windowCoord.y = 0.5*m_pPlayerSettings->getDisplayHeight()-l_cameraCoordinates.y;

	return l_windowCoord;
}

s_coord2d PlayerCamera::transformFromWindowRefToModelRef(s_coord2d _windowCoordinates)
{
	// translation from the window referential to the camera referential.
	s_coord2d l_cameraCoordinates;
	l_cameraCoordinates.x = _windowCoordinates.x - 0.5*m_pPlayerSettings->getDisplayWidth();
	l_cameraCoordinates.y = 0.5*m_pPlayerSettings->getDisplayHeight()-_windowCoordinates.y;

	return transformFromCameraRefToModelRef(l_cameraCoordinates);

}

s_coord2d PlayerCamera::transformFromCameraRefToModelRef(s_coord2d _cameraCoordinates)
{
	

	// translation from the camera referential to the virtual referential.
	s_coord2d l_virtualCoordinates;

	l_virtualCoordinates.x = _cameraCoordinates.x + m_cameraCoords.x;
	l_virtualCoordinates.y = _cameraCoordinates.y + m_cameraCoords.y;

	/*s_coord2d l_strenchingCoordinates;
	l_strenchingCoordinates.x = l_virtualCoordinates.x;
	l_strenchingCoordinates.y = 2*l_virtualCoordinates.y;*/

	s_coord2d l_mapCoordinates;

	l_mapCoordinates.x = ct_rotationCameraToGameCoeffs[m_cameraOrientation][0]*l_virtualCoordinates.x
							+ ct_rotationCameraToGameCoeffs[m_cameraOrientation][1]*l_virtualCoordinates.y;

	l_mapCoordinates.y = ct_rotationCameraToGameCoeffs[m_cameraOrientation][2]*l_virtualCoordinates.x
							+ ct_rotationCameraToGameCoeffs[m_cameraOrientation][3]*l_virtualCoordinates.y;

	s_nbPixels l_nbMapWidth = m_virtualMapWidth/m_cameraZoom;
	s_nbPixels l_nbMapHeight = m_virtualMapHeight/m_cameraZoom;

	s_nbPixels l_spriteWidth = this->getMapSpritesWidth();
	s_nbPixels l_spriteHeight = this->getMapSpritesHeight();

	s_nbPixels l_mapOffsetWidth = 0.5*l_spriteWidth*m_pGameModel->getMapWidth();
	s_nbPixels l_mapOffsetHeight = 0.5*l_spriteHeight*m_pGameModel->getMapHeight();

	l_mapCoordinates.x += l_mapOffsetWidth;
	l_mapCoordinates.y = l_mapOffsetHeight - l_mapCoordinates.y;

	s_coord2d l_modelCoords;

	l_modelCoords.x = l_mapCoordinates.x / l_spriteHeight;
	l_modelCoords.y = l_mapCoordinates.y / l_spriteWidth;

	return l_modelCoords;

}