/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IMarketProvider.h
 *
 * \brief An IMarketProvider is an abstract object able to provide a given volume of Item or RawMaterials objects
 * per turn.
 * Its Item volume consumption per turn relies on
 * - the sensitivity of its state machine to IGameEvent objects
 * - The number of companies requiring the same provided material.
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */
#ifndef _ENGINE_CORE_IMARKETPROVIDER_H
#define _ENGINE_CORE_IMARKETPROVIDER_H

#include <IMarketPlace.h>

class IMarketProvider : public IMarketPlace
{
public:
	IMarketProvider(s_ItemVolume _initial_volume);
	virtual ~IMarketProvider() = 0;

	virtual void transmitEvent(IGameEvent *_event);

	s_ItemVolume getVolumePerTurn();

private:
	// TODO add list of available StorageArea with their respective requested volume per turn

};


#endif /* End _ENGINE_CORE_IMARKETPROVIDER_H */
