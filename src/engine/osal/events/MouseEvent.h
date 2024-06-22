/**
 * The <unnamed> factory builder project.
 *
 * \file src/osal/events/MouseEvent.h
 *
 * \brief An event from the mouse.
 */

/*
 * CHANGELOG:
 * 08/06/2024: File creation (NG)
 */

#ifndef _OSAL8EVENTS_MOUSEEVENT_H
#define _OSAL8EVENTS_MOUSEEVENT_H

#include <Types.h>
#include <ITile.h>
#include <iostream>
#include <vector>
#include <IMouse.h>

/**
 * \brief This is a class implementing mouse events.
*/
class MouseEvent
{
public:
    MouseEvent(s_coord2d _cursor, eMouseKeys _key);

    ~MouseEvent();

    s_coord2d getCoordinates();

    eMouseKeys getKey();

private:
    s_coord2d m_cursor;

    eMouseKeys m_key;
};

#endif /* End _OSAL8EVENTS_MOUSEEVENT_H */