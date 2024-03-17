//
// Created by Niels Grataloup on 20/12/2020.
//

#ifndef FACTORYBUILDER_IGRAPHCOURSESUBSCRIBER_H
#define FACTORYBUILDER_IGRAPHCOURSESUBSCRIBER_H
#include <Types.h>

class IGraphCourseSubscriber
{
public:
	IGraphCourseSubscriber();
	virtual ~IGraphCourseSubscriber() = 0;

	virtual void setCourseDirty() = 0;
};

#endif //FACTORYBUILDER_IGRAPHCOURSESUBSCRIBER_H
