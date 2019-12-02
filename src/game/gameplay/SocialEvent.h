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

#ifndef _GAME_GAMEPLAY_SOCIALEVENT_H
#define _GAME_GAMEPLAY_SOCIALEVENT_H

#include <IEventSubscriber.h>
#include <IGameEvent.h>

enum eSocialEventType
{
	eSocialEventType_ProviderStrike,
	eSocialEventType_PlayerCompanyStrike,
	eSocialEventType_NewLegalLimitForWorkingHours,
};

class ISocialEventSubscriber : public IEventSubscriber
{
public:
	ISocialEventSubscriber();
	virtual	~ISocialEventSubscriber() = 0;

	virtual void post(eSocialEventType _event) = 0;

protected:

};

class SocialEvent : public IGameEvent
{
public:
	SocialEvent(eSocialEventType _type);
	~SocialEvent();

	void notify();

protected:

};

#endif /* End _GAME_GAMEPLAY_SOCIALEVENT_H */
