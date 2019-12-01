/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/ItemFactory.h
 *
 * \brief An ItemFactory is an IProcessStep in charge of transforming an
 * incoming Item or raw material into another Item
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _ENGINE_PRODUCTION_ITEMFACTORY_H
#define _ENGINE_PRODUCTION_ITEMFACTORY_H

#include <IProcessStep.h>
#include <IFacilityTile.h>
#include <Item.h>
#include <Types.h>

class ItemFactory : public IProcessStep, IFacilityTile
{
public:
	ItemFactory();
	~ItemFactory();

private:
	Item *m_ProcessingItem; /*< Item in process (e.g. a car body) */
	s_ProcessUID m_CurrentProcess;
};

#endif /* End _ENGINE_PRODUCTION_ITEMFACTORY_H */
