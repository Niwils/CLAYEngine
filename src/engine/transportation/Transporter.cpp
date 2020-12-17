/*
 * The <unnamed> factory builder project.
 *
 * \file /src/engine/transportation/Transporter.cpp
 *
 * \brief A transporter is an object representing a forklift, train... It carries an ItemContainer.
 */

/*
 * CHANGELOG:
 * 17/12/2020: File creation (NG)
 */

#include <Transporter.h>

Transporter::Transporter(s_ItemContainerQty _nbMaxContainer)
: m_nbMaxContainers(_nbMaxContainer)
, m_CurrentNbContainers(0U)
, m_State(eTransporterState_Idle)
{
 // TODO assert m_nbMaxContainers is not zero.
 mt_Containers = new ObjList<ItemContainer>();
}

Transporter::~Transporter()
{
    // TODO delete carried containers
    delete mt_Containers;
}

bool Transporter::addItemContainer(ItemContainer *_container)
{
    if(m_nbMaxContainers > m_CurrentNbContainers)
    {
        mt_Containers->addObject(_container);
        m_CurrentNbContainers++;

        m_State = eTransporterState_Loading;
        return true;
    }
    else
    {
        return false;
    }
}

ItemContainer *Transporter::getItemContainer(s_ItemTypeUUID _itemType)
{
    ItemContainer * l_return = nullptr;

    ObjListIterator<ItemContainer> *l_iterator = new ObjListIterator<ItemContainer>(mt_Containers);

    ItemContainer *l_it = l_iterator->getCurrent();

    int icpt = 0;
    while((m_CurrentNbContainers > icpt) && (nullptr == l_return))
    {
        if(_itemType == l_it->getCarriedItemType())
        {
            l_return = l_it;
            mt_Containers->removeObject(l_it);
            m_State = eTransporterState_Unloading;
        }
        else
        {
            l_it = l_iterator->iterate();
            icpt++;
        }
    }

    return l_return;
}

bool Transporter::waitingForLoading()
{
    return (eTransporterState_AwaitingToLoad == m_State);
}

bool Transporter::isLoading()
{
    return (eTransporterState_Loading == m_State);
}
bool Transporter::waitingToMove()
{
    return (eTransporterState_AwaitingToMove == m_State);
}

bool Transporter::isMoving()
{
    return (eTransporterState_Moving == m_State);
}

bool Transporter::waitingToUnload()
{
    return (eTransporterState_Loading == m_State);
}

bool Transporter::isUnloading()
{
    return (eTransporterState_Unloading == m_State);
}

void Transporter::runTick()
{
    // TODO implement definition carrying the number of ticks for each action
    // (for each type of transporter)
    switch(m_State)
    {
        case eTransporterState_Idle:
            m_State = eTransporterState_AwaitingToMove;
            break;

        case eTransporterState_AwaitingToMove:
            m_State = eTransporterState_Moving; // TODO add animation management + movement mechanism
            break;

        case eTransporterState_Moving:
            if(0U == m_CurrentNbContainers)
            {
                m_State = eTransporterState_AwaitingToLoad;
            }
            else
            {
                m_State = eTransporterState_AwaitingToUnload;
            }
            break;

        case eTransporterState_AwaitingToLoad:
            break;

        case eTransporterState_Loading:
            break;

        case eTransporterState_AwaitingToUnload:
            break;

        case eTransporterState_Unloading:
            break;

        default:
            // Do nothing
            break;
    };
}