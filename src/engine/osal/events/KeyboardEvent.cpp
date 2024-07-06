/**
 * The CLAYEngine project.
 *
 * \file src/osal/events/KeyboardEvent.cpp
 *
 * \brief An event from the keyboard.
 *
 */

/*
 * CHANGELOG:
 * 08/06/2024: File creation (NG)
 */

#include <KeyboardEvent.h>

KeyboardEvent::KeyboardEvent(eKeyboardKeys _key)
: m_key(_key)
{

}

KeyboardEvent::~KeyboardEvent()
{
    // Do nothing
}

eKeyboardKeys KeyboardEvent::getKey()
{
    return m_key;
}