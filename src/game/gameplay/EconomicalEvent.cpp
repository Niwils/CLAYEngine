/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/gameplay/EconomicalEvent.cpp
 *
 * \brief This file implements the elements needed for the events generated
 * 		by the economy manager
 */

/*
 * CHANGELOG:
 * 30/11/2019: File creation (NG)
 */

#include <EconomicalEvent.h>

EconomicalEvent::EconomicalEvent(eEconomicalEventType _type)
: m_EventType(_type)
{

}

EconomicalEvent::~EconomicalEvent()
{

}


void EconomicalEvent::notify()
{
	ObjList<IEconomicalEventSubscriber> *l_subscribers = getSubscribers();

	// TODO assert on nullptr = l_subscribers
	IEconomicalEventSubscriber *l_iterator = l_subscribers->iterate();

	while(nullptr != l_iterator)
	{
		l_iterator->post(m_EventType);
		l_iterator = l_subscribers->iterate();
	}
}
