/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IGameEvent.h
 *
 * \brief An IGameEvent is an abstract object generated either by the player HMI or by
 * the game Core. Such events can be:
 * - New taxes, laws, economical crisis...
 * - New competitor model.
 * A concrete object inheriting IGameEvent can be for example,
 * an attribute of the economics engine.
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */

#ifndef _ENGINE_CORE_IGAMEEVENT_H
#define _ENGINE_CORE_IGAMEEVENT_H

#include <IEventSubscriber.h>
#include <ObjList.h>

class IGameEvent
{
public:
	IGameEvent()
	{

	}

	virtual ~IGameEvent() = 0;

	void addSubscriber(IEventSubscriber *_subscriber)
	{
		m_Subscribers.addObject(_subscriber);
	}

	void removeSubscriber(IEventSubscriber *_subscriber)
	{
		m_Subscribers.removeObject(_subscriber);

		// TODO check if returns null. If nullptr, raise an assert?
	}

protected:
	// Notification might endorse a more application-centric signaling to
	// IEventSubscriber objects.
	virtual void notify() = 0;

	ObjList<IEventSubscriber> *getSubscribers()
	{
		return &m_Subscribers;
	}

private:
	ObjList<IEventSubscriber> m_Subscribers;
};

#endif /* End _ENGINE_CORE_IGAMEEVENT_H */
