/**
 * The <unnamed> factory builder project.
 *
 * \file src/osal/events/KeyboardEvent.h
 *
 * \brief An event from the keyboard.
 */

/*
 * CHANGELOG:
 * 08/06/2024: File creation (NG)
 */

#ifndef _OSAL8EVENTS8KEYBOARDEVENT_H
#define _OSAL8EVENTS8KEYBOARDEVENT_H

#include <Types.h>
#include <ITile.h>
#include <iostream>
#include <vector>
#include <IKeyboard.h>

/**
 * \brief This is a class implementing keyboard strokes.
*/
class KeyboardEvent
{
public:
    KeyboardEvent(eKeyboardKeys _key);

    ~KeyboardEvent();

    eKeyboardKeys getKey();

private:
    eKeyboardKeys m_key;
};

#endif /* End _OSAL8EVENTS8KEYBOARDEVENT_H */