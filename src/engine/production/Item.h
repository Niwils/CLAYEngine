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
#include <IToken.h>

class Item : public IToken
{
public:
	Item();
	~Item();

private:
	// TODO: manage assembly states
};
