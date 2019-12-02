/*
 * The <unnamed> factory builder project.
 *
 * \file test/containers/ObjList/ObjListTest.h
 *
 * \brief Test for the ObjList container
 */

/*
 * CHANGELOG:
 * 02/12/2019: File creation (NG)
 */

#ifndef _TEST_CONTAINERS_OBJLIST_OBJLISTTEST_H
#define _TEST_CONTAINERS_OBJLIST_OBJLISTTEST_H

#include <ObjList.h>
#include <stdint.h>
#include <cxxtest/TestSuite.h>

class ObjListTest : public CxxTest::TestSuite
{
public:
	ObjListTest();

	~ObjListTest();

	void testObjList();
private:
	ObjList<uint16_t> *m_ListUnderTest;
};

#endif /* End _TEST_CONTAINERS_OBJLIST_OBJLISTTEST_H */
