/*
 * The <unnamed> factory builder project.
 *
 * \file src/game/ProcessFactory.h
 *
 * \brief A ProcessFactory creates an ItemFactory according to the current year,
 * the available R&D level and solutions proposed by the industrial process industry.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _GAME_PROCESSFACTORY_H
#define _GAME_PROCESSFACTORY_H

#include <IToken.h>

class ProcessFactory
{
public:
	ProcessFactory();
	~ProcessFactory();

private:
	// TODO add Process type
	// TODO add required Item or raw materials settings
	// TODO add resulting Item settings
};

#endif /* End _GAME_PROCESSFACTORY_H */
