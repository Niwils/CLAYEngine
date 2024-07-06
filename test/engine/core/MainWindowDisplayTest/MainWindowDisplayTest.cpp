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

#include "MainWindowDisplayTest.h"

MainWindowDisplayTest::MainWindowDisplayTest()
: CxxTest::TestSuite()
, m_playerSettings()
, m_osal(nullptr)
, m_playerDisplay(nullptr)
{
	m_osal = new OsalSys();
	m_playerDisplay = new PlayerDisplay(m_osal, m_osal, &m_playerSettings);
}

MainWindowDisplayTest::~MainWindowDisplayTest()
{
	delete m_osal;
}

void MainWindowDisplayTest::testMainWindowDisplayTest()
{
	m_playerSettings.setPlayerDisplayResolution(ePlayerSettingsDisplayResolution_640x480);

	s_errorReturn l_retInit = m_osal->init();

	if (0 == l_retInit)
	{
		s_errorReturn l_ret = m_playerDisplay->createWindow();

		if(l_ret < 0 )
		{
			TS_ASSERT_EQUALS(0, 1);
		}

		SDL_Event e;
		bool quit = false;
		while (!quit){
		    while (SDL_PollEvent(&e)){
		        if (e.type == SDL_QUIT){
		            quit = true;
		        }
		        if (e.type == SDL_KEYDOWN){
		            quit = true;
		        }
		        if (e.type == SDL_MOUSEBUTTONDOWN){
		            quit = true;
		        }
		    }
		}
	}
	else
	{
		TS_ASSERT_EQUALS(0, 1);
	}


}
