/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IEventSubscriber.h
 *
 * \brief An IEventSubscriber is an abstract object interested in/sensible to
 * in synchronous IGameEvents.
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */

#ifndef _ENGINE_CORE_IEVENTSUBSCRIBER_H
#define _ENGINE_CORE_IEVENTSUBSCRIBER_H

class IEventSubscriber
{
public:
	IEventSubscriber();
	virtual ~IEventSubscriber() = 0;

private:
};

#endif /* End _ENGINE_CORE_IEVENTSUBSCRIBER_H */
