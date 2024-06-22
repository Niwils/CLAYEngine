/**
 * The CLAYEngine project.
 *
 * @file /src/engine/osal/common/IMouse.h
 *
 * @brief The entry point for the system OSAL (init and termination)
 */

/*
 * CHANGELOG:
 * 17/03/2024: File creation (NG)
 */

#ifndef _OSAL_COMMON_MOUSE_H
#define _OSAL_COMMON_MOUSE_H


enum eMouseKeys
{
    eMouseKeys_None,
    eMouseKeys_LeftClick,
    eMouseKeys_RightClick,
    eMouseKeys_CenterClick,

    eMouseKeys_WheelUp,
    eMouseKeys_WheelDown,

    eMouseKeys_Max
};

#endif /** End of _OSAL_COMMON_MOUSE_H */