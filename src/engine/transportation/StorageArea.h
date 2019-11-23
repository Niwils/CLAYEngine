/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/transportation/StorageArea.h
 *
 * \brief A StorageArea object is a sink in the transportation graph.
 *	It is connected to an ItemFactory interface. When this latter requires an Item, this object
 *	unloads it from the ContainerCarrier and passes it to the interface.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */
#include <INode.h>

class StorageArea : public INode
{
public:
	StorageArea();
	~StorageArea();

private:
	// TODO add list of ItemContainer
	// TODO add max of ItemContainer
	// TODO add pointer to the ItemFactoryInterface
};
