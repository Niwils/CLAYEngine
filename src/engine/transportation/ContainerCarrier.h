/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/transportation/ContainerCarrier.h
 *
 * \brief A ContainerCarrier object is for example a forklift.
 *
 * In the transportation graph, it is an IToken element with some intelligence:
 * - it carries one or more ItemContainer to a PickupArea to a StorageArea.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _ENGINE_TRANSPORTATION_CONTAINERCARRIER_H
#define _ENGINE_TRANSPORTATION_CONTAINERCARRIER_H

#include <IToken.h>

class ContainerCarrier : public IToken
{
public:
	ContainerCarrier();
	~ContainerCarrier();

private:
	Sprite *m_Sprite;
	// TODO add list of ItemContainer
	// TODO add max of ItemContainer
};

#endif /* End _ENGINE_TRANSPORTATION_CONTAINERCARRIER_H */
