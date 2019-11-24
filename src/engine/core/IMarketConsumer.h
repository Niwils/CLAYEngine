/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IMarketConsumer.h
 *
 * \brief An IMarketConsumer is an abstract object consuming a given volume of finished Item objects
 * per turn.
 * Its Item volume consumption per turn relies on
 * - the sensitivity of its state machine to IGameEvent objects
 * - The Item quality/requirements by the public
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */

#include <IMarketPlace.h>

class IMarketConsumer : public IMarketPlace
{
public:
	IMarketConsumer(s_ItemVolume _initial_volume);
	virtual ~IMarketConsumer() = 0;

	virtual void transmitEvent(IGameEvent *_event);

	s_ItemVolume getVolumePerTurn();

private:
	// TODO add list of available PickupArea

};
