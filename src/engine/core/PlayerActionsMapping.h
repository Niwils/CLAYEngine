/**
 * The CLAYEngine project.
 *
 * @file /src/engine/core/PlayerActionsMapping.h
 *
 * @brief The entry point for the system OSAL (init and termination)
 */

/*
 * CHANGELOG:
 * 17/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_PLAYERACTIONSMAPPING_H
#define _ENGINE_CORE_PLAYERACTIONSMAPPING_H

#include <Types.h>

enum ePlayerKeyboardBindableActions
{
	ePlayerKeyboardBindableActions_CameraTravellingLeft,
	ePlayerKeyboardBindableActions_CameraTravellingRight,
	ePlayerKeyboardBindableActions_CameraTravellingUp,
	ePlayerKeyboardBindableActions_CameraTravellingDown,
	ePlayerKeyboardBindableActions_Max
};

class PlayerKeyboardMapping
{
public:
	PlayerKeyboardMapping();

	~PlayerKeyboardMapping();

	ePlayerKeyboardBindableActions getActionFromKey();

private:

};

#endif /* End _ENGINE_CORE_PLAYERACTIONSMAPPING_H */
