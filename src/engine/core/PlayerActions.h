/*!
 * The CLAYEngine project.
 *
 * \file /src/core/PlayerActions.h
 *
 * \brief Actions from the player interface (once parsed)
 */

/*
 * CHANGELOG:
 * 23/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_PLAYERACTIONS_H
#define _ENGINE_CORE_PLAYERACTIONS_H

#include <Types.h>

/*!
* \brief Enumeration of the actions bindable with the player keyboard and/or mouse.
*/
enum ePlayerActions
{
	ePlayerActions_DoNothing,
	ePlayerActions_CameraTravellingLeft,
	ePlayerActions_CameraTravellingUp,
	ePlayerActions_CameraTravellingRight,
	ePlayerActions_CameraTravellingDown,

	ePlayerActions_Click,
	ePlayerActions_Zoom,
	ePlayerActions_Unzoom
};

#endif
