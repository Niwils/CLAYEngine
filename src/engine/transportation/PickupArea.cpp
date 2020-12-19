/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/transportation/PickupArea.cpp
 *
 * \brief A PickupArea object is an object carrying a limited amount of ItemContainer.
 * It is a source for a transportation graph between two distinct production lines (item building a new item)
 * or a delivery area to a production line (material to item).
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#include <PickupArea.h>
#include <Transporter.h>

PickupArea::PickupArea(s_GraphElementUUID _uuid, s_ItemContainerQty _maxQtyContainers)
: INode(_uuid)
, mt_Containers(nullptr)
, m_nbContainersMax(_maxQtyContainers)
, m_nbCurrentContainers(0U)
{
    mt_Containers = new ObjList<ItemContainer>();
}

PickupArea::~PickupArea()
{
    // TODO remove current containers
    delete mt_Containers;
}

bool PickupArea::addItemToContainer(Item *_item)
{
    s_ItemTypeUUID l_itemID = _item->getItemType();

    ObjListIterator<ItemContainer> *l_iterator = new ObjListIterator<ItemContainer>(mt_Containers);

    ItemContainer *l_it = l_iterator->getCurrent();

    int icpt = 0;
    while((m_nbContainersMax > icpt))
    {
        if(l_itemID == l_it->getCarriedItemType())
        {
            bool l_retAdd = l_it->addItem(_item);

            if(true == l_retAdd)
            {
                return true;
            }
            else
            {
                l_it = l_iterator->iterate();
                icpt++;
            }
        }
        else
        {
            l_it = l_iterator->iterate();
            icpt++;
        }
    }

    return false;
}

IToken *PickupArea::getToken() {

    IToken *l_ret = nullptr;
    if(nullptr != m_CarriedToken)
    {
        Transporter *l_carrier = dynamic_cast<Transporter *>(m_CarriedToken);

        if((true == l_carrier->waitingToMove()))
        {
            if(false == l_carrier->isFull()) // TODO add orders management: is leaving pickup area when not full allowed?
            {
                ItemContainer *l_first = mt_Containers->removeFirst();

                if (nullptr != l_first) {
                    l_carrier->addItemContainer(l_first);
                }
            }
            else
            {
                l_ret = m_CarriedToken;
                Transporter *l_nextCarrier = dynamic_cast<Transporter *>(m_Input->getToken());
                m_CarriedToken = l_nextCarrier;

                if(nullptr != l_nextCarrier)
                {
                    l_nextCarrier->moveToNextTile();
                }
            }
        }
    }

    return l_ret;
}