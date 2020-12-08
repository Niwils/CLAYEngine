/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/Item.h
 *
 * \brief An Item object is an item manufactured by the company from another item or raw materials.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _ENGINE_PRODUCTION_ITEM_H
#define _ENGINE_PRODUCTION_ITEM_H

#include <IToken.h>
#include <Sprite.h>
#include <Types.h>
#include <Recipe.h>

class Item : public IToken
{
public:
	Item(s_ItemTypeUUID _itemType, Recipe *_recipe);
	~Item();

	void upgradeItem(s_ProcessUID _processuid);

	s_ItemTypeUUID getItemType();

	s_ProcessUID getRequiredCurrentProcess();

	s_ItemTypeUUID getCurrentRawMaterial();

	bool processCurrentDone(); // return if current recipe item list has reached the end

private:
	// TODO implement Sprite *m_Sprite;
	s_ItemTypeUUID m_ItemType;
	// TODO: manage assembly states
	RecipeFollower *m_Recipe;
};

#endif /* End _ENGINE_PRODUCTION_ITEM_H */
