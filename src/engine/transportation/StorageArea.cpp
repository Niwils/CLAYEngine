/**
 * The CLAYEngine project.
 *
 * \file /src/engine/transportation/StorageArea.cpp/StorageArea.cpp.h
 *
 * @brief A StorageArea object is a sink in the transportation graph.
 *	It is connected to an ItemFactory interface. When this latter requires an Item, this object
 *	unloads it from the ContainerCarrier and passes it to the interface.
 */

/*
 * CHANGELOG:
 * 30 déc. 2019: File creation (NG)
 */

#include <StorageArea.h>
#include <TransportationTile.h>

StorageArea::StorageArea(s_GraphElementUUID _uuid)
: ITransportationNode(_uuid)
// , IFacilityTile()
, m_ActiveContainers(nullptr)
, m_EmptyContainers(nullptr)
{
	m_ActiveContainers = new ObjList<ItemContainer>();
	m_EmptyContainers = new ObjList<ItemContainer>();
}

StorageArea::~StorageArea()
{

}

void StorageArea::deliverContainer(ItemContainer *_container)
{
	// TODO asser m_Containers is not null
	m_ActiveContainers->addObject(_container);
}

ItemContainer *StorageArea::loadEmptyContainer()
{
	ItemContainer *l_ret = m_EmptyContainers->removeFirst();
	return l_ret;
}

Item *StorageArea::pickRawMaterial(s_ItemTypeUUID _itemType)
{
	ObjListIterator<ItemContainer> *l_it = new ObjListIterator<ItemContainer>(m_ActiveContainers);

	Item *l_ret = nullptr;

	// TODO assert l_it is not null
	while((nullptr != l_it->getCurrent()) && (nullptr==l_ret))
	{
		if(_itemType == l_it->getCurrent()->getCarriedItemType())
		{
			l_ret = l_it->getCurrent()->pickItem();

			if(true == l_it->getCurrent()->isEmpty())
			{
				ItemContainer *l_container = l_it->getCurrent();
				m_ActiveContainers->removeObject(l_container);
				m_EmptyContainers->addObject(l_container);
			}
		}
		else
		{
			l_it->iterate();
		}
	}

	delete l_it;
	return l_ret;
}

bool StorageArea::checkAvailability(s_ItemTypeUUID _itemType)
{
	ObjListIterator<ItemContainer> *l_it = new ObjListIterator<ItemContainer>(m_ActiveContainers);

	bool l_ret = false;

	// TODO assert l_it is not null
	while((nullptr != l_it->getCurrent()) && (false==l_ret))
	{
		if(_itemType == l_it->getCurrent()->getCarriedItemType())
		{
			l_ret = true;
		}
		else
		{
			l_it->iterate();
		}
	}

	delete l_it;
	return l_ret;
}

bool StorageArea::checkAndPickItem(s_ItemTypeUUID _itemType, Item *_pickedItem)
{
	ObjListIterator<ItemContainer> *l_it = new ObjListIterator<ItemContainer>(m_ActiveContainers);

	bool l_ret = false;

	// TODO assert l_it is not null
	while((nullptr != l_it->getCurrent()) && (false==l_ret))
	{
		if(_itemType == l_it->getCurrent()->getCarriedItemType())
		{
			l_ret = true;
			_pickedItem = l_it->getCurrent()->pickItem();
		}
		else
		{
			l_it->iterate();
		}
	}

	delete l_it;
	return l_ret;
}

IToken *StorageArea::getToken(s_GraphElementUUID _caller_uuid)
{
    IToken *l_ret = nullptr;
    if(nullptr != m_CarriedToken)
    {
        Transporter *l_carrier = dynamic_cast<Transporter *>(m_CarriedToken);

        if((l_carrier->getNextGraphElement() == _caller_uuid)
           && (true == l_carrier->waitingToMove()))
        {
            if(false == l_carrier->isEmpty()) // TODO add orders management: is leaving pickup area when not full allowed?
            {
                // TODO add list of accepted contents from ItemContainers
                ItemContainer *l_first = l_carrier->getAnyItemContainer(); // TODO adapt that. However, any container is okay for the moment.

                if (nullptr != l_first) {
                    m_ActiveContainers->addObject(l_first);
                }
            }
            else
            {
                l_ret = m_CarriedToken;
                TransportationTile *l_input = dynamic_cast<TransportationTile *>(m_Input);

                Transporter *l_nextCarrier = dynamic_cast<Transporter *>(l_input->getToken(m_uuid));
                m_CarriedToken = l_nextCarrier;

                if(nullptr != l_nextCarrier)
                {
                    l_nextCarrier->moveToNextTile();
                }
            }
        }
    }
    else
    {
        l_ret = m_CarriedToken;
        TransportationTile *l_input = dynamic_cast<TransportationTile *>(m_Input);

        Transporter *l_nextCarrier = dynamic_cast<Transporter *>(l_input->getToken(m_uuid));
        m_CarriedToken = l_nextCarrier;

        if(nullptr != l_nextCarrier)
        {
            l_nextCarrier->moveToNextTile();
        }
    }

    return l_ret;
}

void StorageArea::lockAccess()
{
	// TODO add mutex lock
}

void StorageArea::unlockAccess()
{
	// TODO add mutex unlock
}
