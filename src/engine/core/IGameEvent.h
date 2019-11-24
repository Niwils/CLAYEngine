/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IGameEvent.h
 *
 * \brief An IGameEvent is an abstract object generated either by the player HMI or by
 * the game Core. Such events can be:
 * - New taxes, laws, economical crisis...
 * - New competitor model.
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */

class IGameEvent
{
public:
	IGameEvent();
	virtual ~IGameEvent();

};
