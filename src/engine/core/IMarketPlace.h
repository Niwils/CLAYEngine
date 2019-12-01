/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IMarketPlace.h
 *
 * \brief An IMarketPlace is an abstract object generating or consuming an Item or RawMaterial objects.
 * Its Item or RawMaterial volume generation/consumption per turn relies on
 * - the sensitivity of its state machine to IGameEvent objects
 * - The Item quality/requirements by the public (in the case of a consumer)
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */

#ifndef _ENGINE_CORE_IMARKETPLACE_H
#define _ENGINE_CORE_IMARKETPLACE_H

#include <Types.h>
#include <IGameEvent.h>

class IMarketPlace
{
public:
	IMarketPlace(s_ItemVolume _initial_volume);
	virtual ~IMarketPlace() = 0;

	virtual void transmitEvent(IGameEvent *_event);

	s_ItemVolume getVolumePerTurn();

private:
	s_ItemVolume m_Volume;

};

#endif /* End _ENGINE_CORE_IMARKETPLACE_H */
