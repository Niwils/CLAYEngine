/*
 * The <unnamed> factory builder project.
 *
 * \file /factorybuilder/src/engine/production/Item.cpp
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 08/12/2020: File creation (niels)
 */

#include <Item.h>

Item::Item(s_ItemTypeUUID _itemType, Recipe *_recipe)
: IToken()
{

}
Item::~Item()
{
    // Do nothing.
}

void Item::upgradeItem(s_ProcessUID _processuid)
{

}

s_ItemTypeUUID Item::getItemType()
{
    return m_ItemType;
}

s_ProcessUID Item::getRequiredCurrentProcess()
{
    return 0; // TODO
}

s_ItemTypeUUID Item::getCurrentRawMaterial()
{
    return 0;
}

bool Item::processCurrentDone()
{
    return false; // TODO
}// return if current recipe item list has reached the end
