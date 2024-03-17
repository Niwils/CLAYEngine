/**
 * The CLAYEngine project.
 *
 * @file /src/engine/transportation/GraphCourse.cpp
 *
 * @brief A GraphCourse object contains the shortest path from a departure UUID to an arrival one.
 */

/*
 * CHANGELOG:
 * 20/12/2020: File creation (NG)
 */

#include <GraphCourse.h>

GraphCourse::GraphCourse(s_GraphElementUUID _departure_uuid, s_GraphElementUUID _arrival_uuid)
: m_departure(_departure_uuid)
, m_arrival(_arrival_uuid)
, mt_path(nullptr)
{
	mt_subscriber = new ObjList<IGraphCourseSubscriber>();
}

GraphCourse::~GraphCourse()
{

}

void GraphCourse::setPath(ObjList<s_GraphElementUUID> *_t_path)
{
    mt_path = _t_path;

    ObjListIterator<IGraphCourseSubscriber> *l_itSubscribers = new ObjListIterator<IGraphCourseSubscriber>(mt_subscriber);
    IGraphCourseSubscriber *l_subscriber = l_itSubscribers->iterate();

    while(nullptr != l_itSubscribers->getCurrent())
	{
    	l_subscriber->setCourseDirty();
    	l_subscriber = l_itSubscribers->iterate();
	}

    delete l_itSubscribers;
}

ObjList<s_GraphElementUUID> *GraphCourse::getPath()
{
    return mt_path;
}

void  GraphCourse::registerSubscriber(IGraphCourseSubscriber *_subscriber)
{
	mt_subscriber->addObject(_subscriber);
}
