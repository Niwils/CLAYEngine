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

s_nbPixels PlayerCamera::getSpritesWidth()
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

s_nbPixels PlayerCamera::getSpritesHeight()
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

void PlayerCamera::initializeCamera()
{
	// Increments are divided by two as we are in isometric 3D.
	s_nbPixels l_increment_x = 0.5*(this->getSpritesWidth());
	s_nbPixels l_increment_y = 0.5*(this->getSpritesHeight());

	s_MapWidth l_mapWidth = m_pGameModel->getMapWidth();
	s_MapHeight l_mapHeight = m_pGameModel->getMapHeight();

	s_coord2d l_icpt;

	m_pOsalSys->clearWindow();

	std::vector<s_bool> *l_tDisplayed = new std::vector<s_bool>(l_mapHeight*l_mapWidth, false);

	/*for(l_icpt.y = 0; m_pGameModel->getMapHeight() > l_icpt.y; l_icpt.y++)
	{
		for(l_icpt.x = 0; m_pGameModel->getMapWidth() > l_icpt.x; l_icpt.x++)
		{
			// We calculate the center position of the sprite within the screen
					s_coord2d l_tileInWindowRef = transformFromModelRefToWindowRef(l_icpt);
					ITile *l_pTile = nullptr;
					l_pTile = m_pGameModel->getTile(l_icpt);
					ISpriteWindow *l_spriteFov = l_pTile->getSpriteWindow();
					l_spriteFov->setupRendering(l_tileInWindowRef, m_cameraZoom,
													m_pPlayerSettings->getDisplayWidth(),
													m_pPlayerSettings->getDisplayHeight()
												);

					m_pOsalSys->displaySprite(l_spriteFov, l_tileInWindowRef, m_cameraZoom);
		}
	}*/
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

/*s_coord2d PlayerCamera::transformFromWindowRefToModelRef(s_coord2d _windowCoordinates)
{
	s_coord2d l_cameraCoords;
	// Positionning the window coordinates within the virtual referential
	s_coord2d l_virtualCoords;

	l_cameraCoords.x = _windowCoordinates.x - 0.5*m_pPlayerSettings->getDisplayWidth();
	l_cameraCoords.y = _windowCoordinates.y - 0.5*m_pPlayerSettings->getDisplayHeight();

	l_virtualCoords.x = m_virtualCenterCoords.x + m_cameraCoords.x + l_cameraCoords.x;
	l_virtualCoords.y = m_virtualCenterCoords.y + m_cameraCoords.y + l_cameraCoords.y;

	s_nbPixels l_spriteWidth = 414U;
	s_nbPixels l_spriteHeight = 212U;

	s_nbPixels l_spriteHalfWidth = 212U;
	s_nbPixels l_spriteHalfHeight = 106U;

	s_coord2d l_modelCoords;

	l_modelCoords.x = l_virtualCoords.x - l_spriteHalfWidth*

	return l_modelCoords;
}*/

s_coord2d PlayerCamera::transformFromModelRefToWindowRef(s_coord2d _modelCoordinates)
{
	s_coord2d l_cameraCoords;
	// Positionning the model coordinates within the virtual referential
	s_coord2d l_virtualCoords;

	s_nbPixels l_spriteWidth = this->getSpritesWidth();
	s_nbPixels l_spriteHeight = this->getSpritesHeight();

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

	// translation from the camera referential to the virtual referential.
	s_coord2d l_virtualCoordinates;

	l_virtualCoordinates.x = l_cameraCoordinates.x + m_cameraCoords.x;
	l_virtualCoordinates.y = l_cameraCoordinates.y + m_cameraCoords.y;

	s_nbPixels l_nbMapWidth = m_virtualMapWidth/m_cameraZoom;
	s_nbPixels l_nbMapHeight = m_virtualMapHeight/m_cameraZoom;

	s_coord2d l_virtualMapTopLeft;
	l_virtualMapTopLeft.x = 0.5*l_nbMapWidth + l_virtualCoordinates.x;
	l_virtualMapTopLeft.y = 0.5*l_nbMapHeight - l_virtualCoordinates.y;

	s_coord2d l_boxCoordinates;

	s_nbPixels l_spriteWidth = this->getSpritesWidth();
	s_nbPixels l_spriteHeight = this->getSpritesHeight();

	s_nbPixels l_boxMapHalfWidth = m_pGameModel->getMapWidth();
	s_nbPixels l_boxMapHalfHeight = m_pGameModel->getMapHeight();
	l_boxCoordinates.x = l_virtualMapTopLeft.x / l_spriteWidth;
	l_boxCoordinates.y = l_virtualMapTopLeft.y / l_spriteHeight;

	s_coord2d l_deltaCoordsInBox;
	
	l_deltaCoordsInBox.x = l_virtualCoordinates.x%l_spriteWidth;
	l_deltaCoordsInBox.y = l_virtualCoordinates.y%l_spriteHeight;

	s_coord2d l_modelCoords;

	// TODO remove
	// Virtual coordinates are centered in the full map.

	// End of TODO

	if((l_boxCoordinates.x < l_boxMapHalfWidth) && (l_boxCoordinates.y < l_boxMapHalfHeight)) // Upper left quadrant.
	{
		if ((((l_boxCoordinates.x %2) == 0) && (l_boxCoordinates.y %2) == 1) // box denotes a North or South side
		|| (((l_boxCoordinates.x %2) == 1) && (l_boxCoordinates.y %2) == 0)
		)
		{
			l_modelCoords.x = (l_boxCoordinates.x-(l_boxMapHalfHeight-l_boxCoordinates.y));
			l_modelCoords.y = (l_boxMapHalfHeight-l_boxCoordinates.y);
			/*if(l_deltaCoordsInBox.y >= 0.5*l_deltaCoordsInBox.x) // click has been done on the North side
			{
				l_modelCoords.x = 
			}
			else // click has been done on the South side
			{

			}*/
		}
		else // box denotes a East or West side
		{
			l_modelCoords.x = (l_boxCoordinates.x-(l_boxMapHalfHeight-l_boxCoordinates.y));
			l_modelCoords.y = (l_boxMapHalfHeight-l_boxCoordinates.y);
			/*if(l_deltaCoordsInBox.x >= 0.5*l_deltaCoordsInBox.y) // click has been done on the East side
			{
				
			}
			else // click has been done on the West side
			{

			}*/
		}
	}
	else if((l_boxCoordinates.x >l_boxMapHalfWidth) && (l_boxCoordinates.y < l_boxMapHalfHeight)) // Upper right quadrant.
	{
		l_modelCoords.x = (l_boxCoordinates.x-(l_boxMapHalfHeight-l_boxCoordinates.y));
			l_modelCoords.y = (l_boxMapHalfHeight-l_boxCoordinates.y);
	}
	else if((l_boxCoordinates.x < l_boxMapHalfWidth) && (l_boxCoordinates.y > l_boxMapHalfHeight)) // Lower left quadrant.
	{
		l_modelCoords.x = (l_boxCoordinates.x-(l_boxMapHalfHeight-l_boxCoordinates.y));
			l_modelCoords.y = (l_boxMapHalfHeight-l_boxCoordinates.y);
	}
	else
	{
		l_modelCoords.x = (l_boxCoordinates.x-(l_boxMapHalfHeight-l_boxCoordinates.y));
			l_modelCoords.y = (l_boxMapHalfHeight-l_boxCoordinates.y);
	}

	return l_modelCoords;
	/*s_coord2d l_gameCoordinates;
		l_gameCoordinates.x = ct_rotationCameraToGameCoeffs[m_cameraOrientation][0]*l_virtualCoordinates.x
						+ ct_rotationCameraToGameCoeffs[m_cameraOrientation][1]*l_virtualCoordinates.y;

		l_gameCoordinates.y = ct_rotationCameraToGameCoeffs[m_cameraOrientation][2]*l_virtualCoordinates.x
						+ ct_rotationCameraToGameCoeffs[m_cameraOrientation][3]*l_virtualCoordinates.y;

		// transform pixels into map tiles
		s_nbPixels l_increment = 212U; // TODO this->getSpritesSize();
*/
		//s_coord2d l_tileCoordinates;

		/*l_gameCoordinates.x += 0.5*m_pGameModel->getMapWidth()*l_increment;
		l_gameCoordinates.y = 0.5*m_pGameModel->getMapHeight()*l_increment-l_gameCoordinates.y;

		l_tileCoordinates.x = l_gameCoordinates.x / l_increment;
		l_tileCoordinates.y = l_gameCoordinates.y / l_increment;*/

		/*if(0<l_tileCoordinates.x)
		{
			if(0<(l_gameCoordinates.x-(l_tileCoordinates.x*l_increment))
			{
			}
		
			
			{
				l_tileCoordinates.x -= 1;
			}
			else
			{
				l_tileCoordinates.x += 1;
			}
		}

		if(0<(l_gameCoordinates.y%l_increment))
		{
			if(0<l_tileCoordinates.y)
			{
				l_tileCoordinates.y -= 1;
			}
			else
			{
				l_tileCoordinates.y += 1;
			}
		}*/
		// moving the coordinates to the model referential.
		/*l_tileCoordinates.x += 0.5*m_pGameModel->getMapWidth();
		l_tileCoordinates.y = 0.5*m_pGameModel->getMapHeight()-l_tileCoordinates.y-1;
	return l_tileCoordinates;*/

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