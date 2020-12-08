/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/production/Conveyor.cpp/Conveyor.cpp.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 19 déc. 2019: File creation (niels)
 */

#include<Conveyor.h>

Conveyor::Conveyor(s_EdgeFifoSize _size)
: IEdge(_size)
{

}

Conveyor::~Conveyor()
{

}

void Conveyor::timeStep()
{
	stepFifo();
}
