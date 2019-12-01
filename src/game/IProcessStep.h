/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/ItemFactory.h
 *
 * \brief An IProcessStep is an INode object in charge of handling an IToken object
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _GAME_IPROCESSSTEP_H
#define _GAME_IPROCESSSTEP_H

#include <INode.h>

class IProcessStep : public INode
{
public:
	IProcessStep();
	virtual ~IProcessStep() = 0;

protected:

};

#endif /* End _GAME_IPROCESSSTEP_H */
