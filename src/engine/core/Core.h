/**
 * The CLAYEngine project.
 *
 * @file /src/engine/core/Core.h
 *
 * @brief The core of the game.
 */

/*
 * CHANGELOG:
 * 21/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_CORE_H
#define _ENGINE_CORE_CORE_H

#include <Types.h>
#include <IGameModel.h>
#include <OsalSys.h>
#include <PlayerDisplay.h>
#include <IGameController.h>

class Core
{
public:
	Core();
	~Core();

	void run();

private:
	IGameModel *m_pModel; // Model
	IOsalSys *m_pOsal; // Support for controller and views
	IGameController *m_pController; // Controller
	PlayerDisplay *m_pView; // View

	bool m_quitHasBeenRequested;
};

#endif /* End _ENGINE_CORE_CORE_H */
