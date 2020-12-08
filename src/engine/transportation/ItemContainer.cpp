/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/transportation/ItemContainer.cpp/ItemContainer.cpp.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 30 déc. 2019: File creation (niels)
 */

#include <ItemContainer.h>

ItemContainer::ItemContainer(s_ItemTypeUUID _itemType, s_ItemQuantity _max_qty)
: m_CarriedItems(nullptr)
, m_CarriedItemType(_itemType)
, m_MaxQty(_max_qty)
, m_CurrentQty(0U)
{
	m_CarriedItems = new ObjList<Item>();
}

ItemContainer::~ItemContainer()
{

}

s_ItemTypeUUID ItemContainer::getCarriedItemType()
{
	return m_CarriedItemType;
}

void ItemContainer::addItem(Item *_item)
{
	// TODO assert isFull() return false?
	// TODO assert m_CarriedItems is not null
	if(false == isFull())
	{
		m_CarriedItems->addObject(_item);
		m_CurrentQty++;
	}

}
Item *ItemContainer::pickItem()
{
	// TODO
	return nullptr;
}

bool ItemContainer::isEmpty()
{
	return (0U == m_CurrentQty) ? true : false;
}

bool ItemContainer::isFull()
{
	return (m_MaxQty == m_CurrentQty) ? true : false;
}

