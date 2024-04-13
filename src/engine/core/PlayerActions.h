/**
 * The CLAYEngine project.
 *
 * @file /src/core/PlayerActions.h
 *
 * @brief Actions from the player interface (once parsed)
 */

/*
 * CHANGELOG:
 * 23/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_PLAYERACTIONS_H
#define _ENGINE_CORE_PLAYERACTIONS_H

#include <Types.h>

enum ePlayerActions
{
	ePlayerActions_CameraTravellingLeft,
	ePlayerActions_CameraTravellingUp,
	ePlayerActions_CameraTravellingRight,
	ePlayerActions_CameraTravellingDown
};

#endif
