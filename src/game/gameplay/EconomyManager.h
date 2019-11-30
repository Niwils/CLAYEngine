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

class EconomyManager
{
public:
	EconomyManager();
	~EconomyManager();

	void tickExec();

private:
 // TODO register EconomicalEvent attributes here.
};
