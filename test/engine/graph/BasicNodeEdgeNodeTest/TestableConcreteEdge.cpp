/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/test/engine/graph/BasicNodeEdgeNodeTest/TestableConcreteEdge.cpp/TestableConcreteEdge.cpp.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 15 déc. 2019: File creation (niels)
 */


#include "TestableConcreteEdge.h"

TestableConcreteEdge::TestableConcreteEdge(s_GraphElementUUID _uuid, s_EdgeFifoSize _size)
: IEdge(_uuid, _size)
{

}

TestableConcreteEdge::~TestableConcreteEdge()
{
}
