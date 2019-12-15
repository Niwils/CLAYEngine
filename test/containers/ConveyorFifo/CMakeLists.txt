CXXTEST_ADD_TEST(conveyorFifoTest mainConveyorFifoTest.cpp 
                    ${CMAKE_CURRENT_LIST_DIR}/ConveyorFifoTest.h ${CMAKE_CURRENT_LIST_DIR}/ConveyorFifoTest.cpp)
	target_link_libraries(conveyorFifoTest engine)