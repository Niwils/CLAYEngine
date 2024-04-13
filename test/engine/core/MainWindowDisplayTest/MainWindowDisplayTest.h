/*
 * The <unnamed> factory builder project.
 *
 * \file test/engine/graph/BasicNodeEdgeNodeTest/BasicNodeEdgeNodeTest.h
 *
 * \brief Test for the bases of graphes.
 */

/*
 * CHANGELOG:
 * 15/12/2019: File creation (NG)
 */

#ifndef _TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_H
#define _TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_H

#include <stdint.h>
#include <OsalSys.h>
#include <PlayerSettings.h>
#include <PlayerDisplay.h>
#include <cxxtest/TestSuite.h>

class MainWindowDisplayTest : public CxxTest::TestSuite
{
public:
	MainWindowDisplayTest();

	~MainWindowDisplayTest();

	void testMainWindowDisplayTest();

private:
	OsalSys *m_osal;

	PlayerSettings m_playerSettings;

	PlayerDisplay *m_playerDisplay;
};

#endif /* End _TEST_ENGINE_GRAPH_BASICNODEEDGENODETEST_H */
