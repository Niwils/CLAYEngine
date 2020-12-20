/**
 * The CLAYEngine project.
 *
 * @file /src/engine/transportation/Transporter.cpp
 *
 * @brief A transporter is an object representing a forklift, train... It carries one or more ItemContainer.
 */

/*
 * CHANGELOG:
 * 17/12/2020: File creation (NG)
 */

#include <Transporter.h>

Transporter::Transporter(s_ItemContainerQty _nbMaxContainer, TransporterDefinition _definition)
: IToken()
, IGraphCourseSubscriber()
, m_transporterRules(_definition)
, m_remainingTicksCurrentState(0U)
, m_nbMaxContainers(_nbMaxContainer)
, m_CurrentNbContainers(0U)
, m_State(eTransporterState_Idle)
, m_graphCourse(nullptr)
, m_currentGraphUUID(0U)
{
 // TODO assert m_nbMaxContainers is not zero.
 mt_Containers = new ObjList<ItemContainer>();
}

Transporter::~Transporter()
{
    ObjListIterator<ItemContainer> *l_it = new ObjListIterator<ItemContainer>(mt_Containers);

    ItemContainer *l_container = l_it->iterate();
    while(nullptr != l_container)
    {
        delete l_container;
        l_container = l_it->iterate();
    }

    delete l_it;

    delete mt_Containers;
}

bool Transporter::addItemContainer(ItemContainer *_container)
{
    if(eTransporterState_Awaiting == m_State) {
        if (m_nbMaxContainers > m_CurrentNbContainers) {
            mt_Containers->addObject(_container);
            m_CurrentNbContainers++;

            m_remainingTicksCurrentState = 0u;
            m_State = eTransporterState_Loading;
            return true;
        } else {
            return false;
        }
    }

    return false;
}

ItemContainer *Transporter::getItemContainer(s_ItemTypeUUID _itemType)
{
    ItemContainer *l_return = nullptr;

    ObjListIterator<ItemContainer> *l_iterator = new ObjListIterator<ItemContainer>(mt_Containers);

    ItemContainer *l_it = l_iterator->getCurrent();


    if(eTransporterState_Awaiting == m_State)
    {

        int icpt = 0;
        while ((m_CurrentNbContainers > icpt) && (nullptr == l_return)) {
            if (_itemType == l_it->getCarriedItemType()) {
                l_return = l_it;
                mt_Containers->removeObject(l_it);
                m_remainingTicksCurrentState = 0U;
                m_State = eTransporterState_Unloading;
            } else {
                l_it = l_iterator->iterate();
                icpt++;
            }
        }
    }

    return l_return;
}

ItemContainer *Transporter::getAnyItemContainer()
{
    ItemContainer *l_return = nullptr;

    if((eTransporterState_Awaiting == m_State)
        && (false == isEmpty()))
    {
        l_return = mt_Containers->removeFirst();
        m_CurrentNbContainers--;
        m_remainingTicksCurrentState = 0U;
        m_State = eTransporterState_Unloading;
    }

    return l_return;
}

bool Transporter::isFull()
{
    return (m_nbMaxContainers == m_CurrentNbContainers);
}

bool Transporter::isEmpty()
{
    return (0U == m_CurrentNbContainers);
}

bool Transporter::moveToNextTile()
{
    bool l_ret = false;
    if(eTransporterState_Awaiting == m_State)
    {
        m_remainingTicksCurrentState = 0U;
        m_graphIterator->iterate();
        m_State = eTransporterState_Moving;
        l_ret = true;
    }
    else if(eTransporterState_Moving == m_State)
    {
        if((m_transporterRules.m_nbTicksToCrossATile-1) == m_remainingTicksCurrentState)
        {
            m_remainingTicksCurrentState = 0U;
            m_State = eTransporterState_Moving;
            l_ret = true;
        }
        else
        {
            l_ret = false;
        }
    }

    return l_ret;
}

bool Transporter::isLoading()
{
    return (eTransporterState_Loading == m_State);
}
bool Transporter::waitingToMove()
{
    return (eTransporterState_Awaiting == m_State);
}

bool Transporter::isMoving()
{
    return (eTransporterState_Moving == m_State);
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
            m_State = eTransporterState_Awaiting;
            break;

        case eTransporterState_Moving:
            if(m_transporterRules.m_nbTicksToCrossATile > m_remainingTicksCurrentState)
            {
                m_remainingTicksCurrentState++;
            }
            else
            {
                m_State = eTransporterState_Awaiting;
            }
            break;

        case eTransporterState_Awaiting:
            // Do nothing
            break;

        case eTransporterState_Loading:
            if(m_transporterRules.m_nbTicksToLoad > m_remainingTicksCurrentState)
            {
                m_remainingTicksCurrentState++;
            }
            else
            {
                m_State = eTransporterState_Awaiting;
            }
            break;

        case eTransporterState_Unloading:
            if(m_transporterRules.m_nbTicksToUnload > m_remainingTicksCurrentState)
            {
                m_remainingTicksCurrentState++;
            }
            else
            {
                m_State = eTransporterState_Awaiting;
            }
            break;

        default:
            // Do nothing // TODO assert?
            break;
    };
}

void Transporter::setGraphCourse(GraphCourse *_course)
{
    m_graphCourse = _course;

    if(nullptr != m_graphCourse)
    {
        m_graphIterator = new ObjListIterator<s_GraphElementUUID>(m_graphCourse->getPath());

        s_GraphElementUUID *l_uuid = m_graphIterator->iterate();

        while (m_currentGraphUUID != *l_uuid) // Player is not allowed to change an IGraphElement if used by a token.
        {
            l_uuid = m_graphIterator->iterate();
        }
        // TODO what if current UUID is no longer part of the graph? Make a temporary graph?
    }
}

s_GraphElementUUID Transporter::getNextGraphElement()
{
    s_GraphElementUUID *l_ret = 0U;

    if(nullptr != m_graphIterator)
    {
        l_ret = m_graphIterator->getCurrent();
    }

    return *l_ret;
}

void Transporter::setCourseDirty()
{
	// TODO
}