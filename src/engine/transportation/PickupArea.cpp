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

PickupArea::PickupArea(s_ItemContainerQty _maxQtyContainers)
: mt_Containers(nullptr)
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

void PickupArea::runTick()
{
    if(nullptr != m_CarriedToken)
    {
        Transporter *l_carrier = dynamic_cast<Transporter *>(m_CarriedToken);

        if((true == l_carrier->waitingForLoading()))
        {
            ItemContainer *l_first = mt_Containers->removeFirst();
            l_carrier->addItemContainer(l_first);
            l_carrier->runTick();
        }
    }
}