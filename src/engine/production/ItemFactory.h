/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/production/ItemFactory.h/ItemFactory.h.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 27 déc. 2019: File creation (niels)
 */

#ifndef SRC_ENGINE_PRODUCTION_ITEMFACTORY_H_
#define SRC_ENGINE_PRODUCTION_ITEMFACTORY_H_

#include <INode.h>
#include <ITimeEventSubscriber.h>
#include <ProductionPlanning.h>

class ItemFactory : public INode, ITimeEventSubscriber
{
public:
	ItemFactory();
	~ItemFactory();

	ProductionPlanning *getPlanning();

	void timeStep();

private:
	ProductionPlanning *m_Planning;

	enum eItemFactoryState
	{
		eItemFactoryState_Init,
		eItemFactoryState_AwaitPlanning,
		eItemFactoryState_AwaitParts,
		eItemFactoryState_ProduceItem,
		eItemFactoryState_ReleaseItem,
		eItemFactoryState_Stuck
	};

	eItemFactoryState m_State;
};



#endif /* SRC_ENGINE_PRODUCTION_ITEMFACTORY_H_ */
