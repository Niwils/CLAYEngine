/**
 * The CLAYEngine project.
 *
 * \file src/osal/events/MouseEvent.cpp
 *
 * \brief An event from the mouse.
 *
 */

/*
 * CHANGELOG:
 * 08/06/2024: File creation (NG)
 */

#include <MouseEvent.h>

MouseEvent::MouseEvent(s_coord2d _cursor, eMouseKeys _key)
: m_cursor(_cursor)
, m_key(_key)
{

}

MouseEvent::~MouseEvent()
{
    // Do nothing
}

s_coord2d MouseEvent::getCoordinates()
{
    return m_cursor;
}

eMouseKeys MouseEvent::getKey()
{
    return m_key;
}