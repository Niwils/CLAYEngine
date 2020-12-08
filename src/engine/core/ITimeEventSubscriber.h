/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/core/ITimeEventSubscriber.h/ITimeEventSubscriber.h.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 27 déc. 2019: File creation (niels)
 */

#ifndef SRC_ENGINE_CORE_ITIMEEVENTSUBSCRIBER_H_
#define SRC_ENGINE_CORE_ITIMEEVENTSUBSCRIBER_H_
#include <IEventSubscriber.h>

class ITimeEventSubscriber : public IEventSubscriber
{
public:
	ITimeEventSubscriber();
	virtual ~ITimeEventSubscriber();

	virtual void timeStep() = 0;
};




#endif /* SRC_ENGINE_CORE_ITIMEEVENTSUBSCRIBER_H_ */
