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

#include <INode.h>
#include <IEdge.h>
#include <IFacilityTile.h>
#include <Item.h>
#include <ITimeEventSubscriber.h>
#include <Types.h>
#include <StorageArea.h>


class ItemProcessor : public INode, IFacilityTile, ITimeEventSubscriber
{
public:
	ItemProcessor(s_ProcessUID *_supported_processes, s_ArrayQtyNumber _nb_supported_processes);
	~ItemProcessor();

	void timeStep();

private:
	Item *m_ProcessingItem; /*< Item in process (e.g. a car body) */
	s_ProcessUID m_CurrentProcess;

	enum eItemProcessorState
	{
		eItemProcessorState_Init,
		eItemProcessorState_Idle,
		eItemProcessorState_ConfigureAssignedTask,
		eItemProcessorState_AwaitPart,
		eItemProcessorState_ProduceItem,
		eItemProcessorState_ReleaseItem,
		eItemProcessorState_Stuck
	};

	eItemProcessorState m_State;

	s_ProcessUID *m_SupportedProcesses;
	s_ArrayQtyNumber m_NbSupportedProcesses;

	StorageArea *m_ItemPickupPoint;

	s_NumberofRounds m_NbTurnsForThisItem;
	s_NumberofRounds m_ProcessNbTurns;
};

#endif /* End _ENGINE_PRODUCTION_ITEMFACTORY_H */
