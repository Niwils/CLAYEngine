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

class Item : public IToken
{
public:
	Item();
	~Item();

	void upgradeItem()

private:
	Sprite *m_Sprite;
	// TODO: manage assembly states
};

#endif /* End _ENGINE_PRODUCTION_ITEM_H */
