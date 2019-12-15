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

#include "ConveyorFifoTest.h"

ConveyorFifoTest::ConveyorFifoTest()
: CxxTest::TestSuite()
{
	m_FifoUnderTest = new ConveyorFifo<uint16_t>(4U);
}

ConveyorFifoTest::~ConveyorFifoTest()
{
	delete m_FifoUnderTest;
}

void ConveyorFifoTest::testConveryorFifo()
{
	uint16_t l_testNb[3];

	uint16_t *l_testRt[4] =
			{
					nullptr, nullptr, nullptr, nullptr
			};

	for(uint16_t icpt = 0U; 3U > icpt; icpt++)
	{
		l_testNb[icpt] = icpt+1;
		m_FifoUnderTest->stepFifo();
		m_FifoUnderTest->queue(&l_testNb[icpt]);
	}

	for(uint16_t icpt = 0; 4U > icpt; icpt++)
	{
		uint16_t *l_ret = nullptr;

		l_ret = m_FifoUnderTest->unqueue();

		TS_ASSERT_EQUALS(l_ret, nullptr);
	}

	for(uint16_t icpt = 0; 4U > icpt; icpt++)
	{
		m_FifoUnderTest->stepFifo();
		l_testRt[icpt] = m_FifoUnderTest->unqueue();
	}

	TS_ASSERT_EQUALS(l_testRt[0], &l_testNb[0]);
	TS_ASSERT_EQUALS(l_testRt[1], &l_testNb[1]);
	TS_ASSERT_EQUALS(l_testRt[2], &l_testNb[2]);
	TS_ASSERT_EQUALS(l_testRt[3], nullptr);

}
