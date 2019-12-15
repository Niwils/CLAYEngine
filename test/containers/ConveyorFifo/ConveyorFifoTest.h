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

#ifndef _TEST_CONTAINERS_CONVEYORFIFO_CONVEYORFIFOTEST_H
#define _TEST_CONTAINERS_CONVEYORFIFO_CONVEYORFIFOTEST_H

#include <ConveyorFifo.h>
#include <stdint.h>
#include <cxxtest/TestSuite.h>

class ConveyorFifoTest : public CxxTest::TestSuite
{
public:
	ConveyorFifoTest();

	~ConveyorFifoTest();

	void testConveryorFifo();
private:
	ConveyorFifo<uint16_t> *m_FifoUnderTest;
};

#endif /* End _TEST_CONTAINERS_CONVEYORFIFO_CONVEYORFIFOTEST_H */
