/**
 * The CLAYEngine project.
 *
 * @file /src/engine/transportation/GraphCourse.h
 *
 * @brief A GraphCourse object contains the shortest path from a departure UUID to an arrival one.
 */

/*
 * CHANGELOG:
 * 20/12/2020: File creation (NG)
 */

#ifndef FACTORYBUILDER_GRAPHCOURSE_H
#define FACTORYBUILDER_GRAPHCOURSE_H

#include <Types.h>
#include <ObjList.h>
#include <IGraphCourseSubscriber.h>

class GraphCourse
{
public:
    GraphCourse(s_GraphElementUUID _departure_uuid, s_GraphElementUUID _arrival_uuid);

    ~GraphCourse();

    void setPath(ObjList<s_GraphElementUUID> *_t_path);

    ObjList<s_GraphElementUUID> *getPath();

    void registerSubscriber(IGraphCourseSubscriber *_subscriber);

private:
    s_GraphElementUUID m_departure;
    s_GraphElementUUID m_arrival;
    ObjList<s_GraphElementUUID> *mt_path;

    ObjList<IGraphCourseSubscriber> *mt_subscriber;
    bool m_isDirty;
};


#endif //FACTORYBUILDER_GRAPHCOURSE_H
