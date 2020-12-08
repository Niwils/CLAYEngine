/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/osal/common/ITimeKeeper.h/ITimeKeeper.h.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 31 déc. 2019: File creation (niels)
 */

#ifndef SRC_ENGINE_OSAL_COMMON_ITIMEKEEPER_H_
#define SRC_ENGINE_OSAL_COMMON_ITIMEKEEPER_H_

#include <IGameEvent.h>
#include <Types.h>

class ITimeKeeper : public IGameEvent
{
public:
	ITimeKeeper(s_Tick _tickRate);
	virtual void ~ITimeKeeper() = 0;

	void runTick();

protected:
	virtual void notify();

private:
	s_Tick m_TickRate;
};



#endif /* SRC_ENGINE_OSAL_COMMON_ITIMEKEEPER_H_ */
