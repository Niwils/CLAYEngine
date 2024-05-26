/*
 * The <unnamed> factory builder project.
 *
 * \file test/engine/core/CameraPlayerDisplayTest/CameraPlayerDisplayTest.h
 *
 * \brief Test showing the basic camera player
 */

/*
 * CHANGELOG:
 * 21/04/2024: File creation (NG)
 */

#ifndef _TEST_ENGINE_CORE_CAMERAPLAYERDISPLAYTEST_H
#define _TEST_ENGINE_CORE_CAMERAPLAYERDISPLAYTEST_H

#include <stdint.h>
#include <OsalSys.h>
#include <PlayerSettings.h>
#include <PlayerDisplay.h>
#include <Sprite.h>
#include <WorldElementDefinition.h>
#include <WorldElement.h>
#include <cxxtest/TestSuite.h>
#include "ConcreteGameModel.h"

class CameraPlayerDisplayTest : public CxxTest::TestSuite
{
public:
	CameraPlayerDisplayTest();

	~CameraPlayerDisplayTest();

	void testCameraPlayerDisplayTest();

private:
	OsalSys *m_osal;

	PlayerSettings m_playerSettings;

	PlayerDisplay *m_playerDisplay;

	WorldElementDefinition *m_worldElementDefRed;
	WorldElementDefinition *m_worldElementDefBlue;

	ConcreteGameModel *m_pModel;

	ISprite *m_pSpriteRed;
	ISprite *m_pSpriteBlue;
};

#endif /* End _TEST_ENGINE_CORE_CAMERAPLAYERDISPLAYTEST_H */
