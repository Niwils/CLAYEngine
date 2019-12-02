/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/gameplay/EconomyManager.h
 *
 * \brief The SocialManager is an SocialEvent trigger source.
 * 	It bases the creation of events on the player inputs and the Economical.
 * 	Its state modification is established at each tick.
 */

/*
 * CHANGELOG:
 * 30/11/2019: File creation (NG)
 */

#ifndef _GAME_GAMEPLAY_SOCIALMANAGER_H
#define _GAME_GAMEPLAY_SOCIALMANAGER_H

#include <IGameEvent.h>
#include <SocialEvent.h>
#include <EconomicalEvent.h>

class SocialManager : public IEconomicalEventSubscriber
{
public:
	SocialManager();
	~SocialManager();

	void tickExec();

	void post(eSocialEventType _type);

	void registerToSocialEvent(SocialEventSubscriber *_subscriber, eSocialEventType _event);

private:
	SocialEvent m_cheaperLoans;
	SocialEvent m_higherLoans;
	SocialEvent m_lowerExportCurrency;
	SocialEvent m_higherExportCurrency;
	SocialEvent m_Crisis;

	enum eSocialManagerState
	{
		eEconomicalManagerState_Init,
		eEconomicalManagerState_Nominal,
		eEconomicalManagerState_ProviderStrike,
		eEconomicalManagerState_PlayerCompanyStrike
	};

	eSocialManagerState m_State;
};

#endif /* End _GAME_GAMEPLAY_SOCIALMANAGER_H */
