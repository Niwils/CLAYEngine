/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/gameplay/EconomicalEvent.h
 *
 * \brief This file contains the elements needed for the events generated
 * 		by the economy manager
 */

/*
 * CHANGELOG:
 * 30/11/2019: File creation (NG)
 */

#ifndef _GAME_GAMEPLAY_ECONOMICALEVENT_H
#define _GAME_GAMEPLAY_ECONOMICALEVENT_H

#include <IEventSubscriber.h>
#include <IGameEvent.h>

enum eEconomicalEventType
{
	eEconomicalEventType_CheaperLoans,
	eEconomicalEventType_HigherLoans,
	eEconomicalEventType_ExportCurrencyCheaper,
	eEconomicalEventType_ExportCurrencyHigher,
	eEconomicalEventType_Crisis
};

class IEconomicalEventSubscriber : public IEventSubscriber
{
public:
	IEconomicalEventSubscriber();
	virtual ~IEconomicalEventSubscriber() = 0;

	virtual void post(eEconomicalEventType _event) = 0;

protected:

};

class EconomicalEvent : public IGameEvent
{
public:
	EconomicalEvent(eEconomicalEventType _type);
	~EconomicalEvent();

	void notify();

private:
	eEconomicalEventType m_EventType;
};

#endif /* End _GAME_GAMEPLAY_ECONOMICALEVENT_H */
