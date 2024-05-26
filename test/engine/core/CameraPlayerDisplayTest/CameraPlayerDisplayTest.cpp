/*
 * The <unnamed> factory builder project.
 *
 * \file test/containers/ObjList/ObjListTest.h
 *
 * \brief Implementation of the test for the ObjList container
 */

/*
 * CHANGELOG:
 * 02/12/2019: File creation (NG)
 */

#include "CameraPlayerDisplayTest.h"

// namespace fs = std::filesystem;

CameraPlayerDisplayTest::CameraPlayerDisplayTest()
: CxxTest::TestSuite()
, m_playerSettings()
, m_osal(nullptr)
, m_playerDisplay(nullptr)
, m_worldElementDefRed(nullptr)
, m_worldElementDefBlue(nullptr)
, m_pModel(nullptr)
, m_pSpriteRed(nullptr)
, m_pSpriteBlue(nullptr)
{
	m_playerSettings.setPlayerDisplayResolution(ePlayerSettingsDisplayResolution_1024x768);
	m_osal = new OsalSys();
	m_pModel = new ConcreteGameModel(4U, 4U);
	m_playerDisplay = new PlayerDisplay(m_osal, &m_playerSettings);
}

CameraPlayerDisplayTest::~CameraPlayerDisplayTest()
{
	delete m_playerDisplay;
	delete m_pModel;
	delete m_osal;
}

void CameraPlayerDisplayTest::testCameraPlayerDisplayTest()
{
	s_errorReturn l_retInit = m_osal->init();

	if (0 == l_retInit)
	{
		s_errorReturn l_ret = m_playerDisplay->createWindow();

		if(l_ret < 0 )
		{
			TS_ASSERT_EQUALS(0, 1);
		}

		s_coord2d l_centerSprite;
		l_centerSprite.x = 184U;
		l_centerSprite.y = 106U;

		m_pSpriteRed = m_osal->loadSprite("../assets/basicTiles/basicTile_1_2_red.bmp",
								212U, 424U, 0U, 1U, l_centerSprite);
		m_pSpriteBlue = m_osal->loadSprite("../assets/basicTiles/basicTile_1_2_blue.bmp",
									212U, 424U, 0U, 1U, l_centerSprite);

		m_playerDisplay->setModel(m_pModel);

		m_worldElementDefRed = new WorldElementDefinition(0, m_pSpriteRed, false);
		m_worldElementDefBlue = new WorldElementDefinition(0, m_pSpriteBlue, false);

		WorldElement *l_pTileRed = new WorldElement(m_worldElementDefRed);
		WorldElement *l_pTileBlue = new WorldElement(m_worldElementDefBlue);
		s_coord2d l_coord = {0U, 0U};
		m_pModel->setTile(l_coord, l_pTileRed);
		l_coord = {0U, 1U};
		m_pModel->setTile(l_coord, l_pTileBlue);
		l_coord = {0U, 2U};
		m_pModel->setTile(l_coord, l_pTileRed);
		l_coord = {0U, 3U};
		m_pModel->setTile(l_coord, l_pTileBlue);

		l_coord = {1U, 0U};
		m_pModel->setTile(l_coord, l_pTileBlue);
		l_coord = {1U, 1U};
		m_pModel->setTile(l_coord, l_pTileRed);
		l_coord = {1U, 2U};
		m_pModel->setTile(l_coord, l_pTileBlue);
		l_coord = {1U, 3U};
		m_pModel->setTile(l_coord, l_pTileRed);

		l_coord = {2U, 0U};
		m_pModel->setTile(l_coord, l_pTileRed);
		l_coord = {2U, 1U};
		m_pModel->setTile(l_coord, l_pTileBlue);
		l_coord = {2U, 2U};
		m_pModel->setTile(l_coord, l_pTileRed);
		l_coord = {2U, 3U};
		m_pModel->setTile(l_coord, l_pTileBlue);

		l_coord = {3U, 0U};
		m_pModel->setTile(l_coord, l_pTileBlue);
		l_coord = {3U, 1U};
		m_pModel->setTile(l_coord, l_pTileRed);
		l_coord = {3U, 2U};
		m_pModel->setTile(l_coord, l_pTileBlue);
		l_coord = {3U, 3U};
		m_pModel->setTile(l_coord, l_pTileRed);

 		m_playerDisplay->switchToGameCamera();
		
		SDL_Event e;
		bool quit = false;
		while (!quit){
		    while (SDL_PollEvent(&e)){
		        if (e.type == SDL_QUIT){
		            quit = true;
		        }
		        if (e.type == SDL_KEYDOWN){
		            // m_playerDisplay->switchToGameCamera();
		        }
		        if (e.type == SDL_MOUSEBUTTONDOWN){
		            //quit = true;
		        }
		    }
		}
	}
	else
	{
		TS_ASSERT_EQUALS(0, 1);
	}
	m_osal->exit();

}
