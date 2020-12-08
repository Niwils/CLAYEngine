/*
 * The <unnamed> factory builder project.
 *
 * \file test/containers/ObjList/ObjListTest.h
 *
 * \brief Implementation of the test for the ObjList container
 */

/*
 * CHANGELOG:
 * 02/12/2019: File creation (NG)
 */

#include "ObjListTest.h"

ObjListTest::ObjListTest()
: CxxTest::TestSuite()
{
	m_ListUnderTest = new ObjList<uint16_t>();
}

ObjListTest::~ObjListTest()
{
	delete m_ListUnderTest;
}

void ObjListTest::testObjList()
{
	uint16_t l_testNb[3];

	for(uint16_t icpt = 0; 3 > icpt; icpt++)
	{
		l_testNb[icpt] = icpt;
		m_ListUnderTest->addObject(&(l_testNb[icpt]));
	}

	ObjListIterator<uint16_t> *l_it = new ObjListIterator<uint16_t>(m_ListUnderTest);

	uint16_t *l_cursor = nullptr;
	l_cursor = l_it->iterate();

	while(nullptr != l_cursor)
	{
		*l_cursor = 0xFFFF - *l_cursor;
		l_cursor = l_it->iterate();
	}

	TS_ASSERT_EQUALS(l_testNb[0], 0xFFFF);
	TS_ASSERT_EQUALS(l_testNb[1], 0xFFFE);
	TS_ASSERT_EQUALS(l_testNb[2], 0xFFFD);

	delete l_it;

}
