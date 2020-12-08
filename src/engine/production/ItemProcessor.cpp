/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/production/ItemProcessor.cpp/ItemProcessor.cpp.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 27 déc. 2019: File creation (niels)
 */

#include <ItemProcessor.h>

ItemProcessor::ItemProcessor(s_ProcessUID *_supported_processes, s_ArrayQtyNumber _nb_supported_processes)
: INode()
, IFacilityTile()
, ITimeEventSubscriber()
, m_ProcessingItem(nullptr)
, m_State(eItemProcessorState_Init)
, m_SupportedProcesses(nullptr)
, m_NbSupportedProcesses(_nb_supported_processes)
, m_ItemPickupPoint(nullptr)
, m_NbTurnsForThisItem(0U)
, m_ProcessNbTurns(0U)
{
	m_SupportedProcesses = _supported_processes;
}

ItemProcessor::~ItemProcessor()
{

}

void ItemProcessor::timeStep()
{
	// TODO assert:
	// m_SupportedProcesses is not null
	switch(m_State)
	{
		case eItemProcessorState_Init:
			m_State = eItemProcessorState_Idle;
			break;

		case eItemProcessorState_Idle:
		{
			// TODO assert IToken is null

			m_CarriedToken = m_Input->getToken();

			if(nullptr != m_CarriedToken)
			{
				m_ProcessingItem = dynamic_cast<Item*>(m_CarriedToken);

				if(nullptr == m_ProcessingItem)
				{
					// TODO assert here. Conversion went bad.
				}
				else
				{
					if(m_ProcessingItem->getRequiredCurrentProcess() == m_CurrentProcess)
					{
						// No time penalty. Go directly to awaited parts.
						m_State = eItemProcessorState_AwaitPart;
					}
					else
					{
						m_State = eItemProcessorState_ConfigureAssignedTask;
					}
				}
			}
			break;
		}

		case eItemProcessorState_ConfigureAssignedTask:
			// TODO
			m_State = eItemProcessorState_AwaitPart;
			break;

		case eItemProcessorState_AwaitPart:
		{
			// Currently, just a basic polling, consuming one Item per turn.
			// TODO add requests to the transportation supervisor for priority.
			s_ItemTypeUUID l_tokenRawMat = m_ProcessingItem->getCurrentRawMaterial();

			m_ItemPickupPoint->lockAccess();
			Item *l_picked = nullptr;
			if(true == m_ItemPickupPoint->checkAndPickItem(l_tokenRawMat, l_picked))
			{
				// TODO assert l_picked != null
				delete l_picked;
				m_NbTurnsForThisItem = 0U;
				m_State=eItemProcessorState_ProduceItem;
			}
			m_ItemPickupPoint->unlockAccess();
			break;
		}

		case eItemProcessorState_ProduceItem:
		{
			m_NbTurnsForThisItem++;

			// TODO: add specific time to use a raw_material/part?
			if(m_ProcessNbTurns == m_NbTurnsForThisItem)
			{
				if(true == m_ProcessingItem->processCurrentDone())
				{
					m_State = eItemProcessorState_ReleaseItem;
				}
				else
				{
					m_State = eItemProcessorState_AwaitPart;
				}
			}
			break;
		}

		case eItemProcessorState_ReleaseItem:
		{
			IEdge *l_output = dynamic_cast<IEdge*>(m_Outputs);

			if(false == l_output->getFifo()->isFifoFull())
			{
				l_output->getFifo()->queue(m_ProcessingItem);
				m_ProcessingItem = nullptr;
				m_CarriedToken = nullptr;
				m_State = eItemProcessorState_Idle;
			}
			break;
		}
		case eItemProcessorState_Stuck:
			// TODO alert player trough UI
			break;

	}
}
