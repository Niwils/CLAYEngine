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

#include "BasicHashMapTest.h"

BasicHashMapTest::BasicHashMapTest()
: CxxTest::TestSuite()
{
	m_theHashMap = new HashHeap<s_HashHeapDepth, s_HashHeapDepth *>();
}

BasicHashMapTest::~BasicHashMapTest()
{
	delete m_theHashMap;
}

void BasicHashMapTest::testBasicHashMapTest()
{
	m_theHashMap->addObj(0, nullptr);
	m_theHashMap->addObj(1, nullptr);
	m_theHashMap->addObj(2, nullptr);
	m_theHashMap->addObj(3, nullptr);
	m_theHashMap->addObj(4, nullptr);

	TS_ASSERT_EQUALS(m_theHashMap->getTop()->getHash(), 1);
}
