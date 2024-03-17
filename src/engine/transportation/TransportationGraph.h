/**
 * The CLAYEngine project.
 *
 * @file /src/engine/graph/IGraph.h
 *
 * @brief A TransportationGraph contains all transportation nodes and edges for the item transportation.
 */

/*
 * CHANGELOG:
 * 20/12/2020: File creation (NG)
 */

#ifndef FACTORYBUILDER_TRANSPORTATIONGRAPH_H
#define FACTORYBUILDER_TRANSPORTATIONGRAPH_H

#include <IGraph.h>

class TransportationGraph : public IGraph
{
public:
	TransportationGraph();
	~TransportationGraph();

	void buildGraphCourses();

protected:

};


#endif //FACTORYBUILDER_TRANSPORTATIONGRAPH_H
