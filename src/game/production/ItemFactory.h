/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/ItemFactory.h
 *
 * \brief An ItemFactory is an IProcessStep in charge of transforming an
 * incoming Item or raw material into another Item
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#include <IProcessStep.h>

class ItemFactory : public IProcessStep
{
public:
	ItemFactory();
	~ItemFactory();

private:

};
