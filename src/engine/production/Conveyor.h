/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/production/Conveyor.h/Conveyor.h.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 19 déc. 2019: File creation (niels)
 */

#include <IEdge.h>

#ifndef SRC_ENGINE_PRODUCTION_CONVEYOR_H_
#define SRC_ENGINE_PRODUCTION_CONVEYOR_H_

class Conveyor : public IEdge
{
public:
	Conveyor(s_EdgeFifoSize _size);
	~Conveyor();

	void timeStep();

};



#endif /* SRC_ENGINE_PRODUCTION_CONVEYOR_H_ */
