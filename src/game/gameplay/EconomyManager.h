/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/gameplay/EconomyManager.h
 *
 * \brief The EconomyManager is an EconomicalEvent factory.
 * 	It bases the creation of events on the player inputs and the SocialManager.
 * 	Its state modification is established at each tick.
 */

/*
 * CHANGELOG:
 * 30/11/2019: File creation (NG)
 */

#ifndef _GAME_GAMEPLAY_ECONOMYMANAGER_H
#define _GAME_GAMEPLAY_ECONOMYMANAGER_H

#include <IGameEvent.h>
#include <SocialEvent.h>
#include <EconomicalEvent.h>

class EconomyManager : public SocialEventSubscriber
{
public:
	EconomyManager();
	~EconomyManager();

	void tickExec();

	void post(eSocialEventType _type);

	void registerToEconomicalEvent(EconomicalEventSubscriber *_subscriber, eSocialEventType _event);

private:
	EconomicalEvent m_cheaperLoans;
	EconomicalEvent m_higherLoans;
	EconomicalEvent m_lowerExportCurrency;
	EconomicalEvent m_higherExportCurrency;
	EconomicalEvent m_Crisis;

	enum eEconomicalManagerState
	{
		eEconomicalManagerState_Init,
		eEconomicalManagerState_Nominal,
		eEconomicalManagerState_Speculation,
		eEconomicalManagerState_Crash,
		eEconomicalManagerState_GovernmentFund
	};

	eEconomicalManagerState m_State;
};

#endif /* End _GAME_GAMEPLAY_ECONOMYMANAGER_H */
