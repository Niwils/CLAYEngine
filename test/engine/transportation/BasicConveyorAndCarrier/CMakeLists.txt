CXXTEST_ADD_TEST(basicConveyorAndCarrier mainBasicConveyorAndCarrier.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/BasicConveyorAndCarrier.h
                    ${CMAKE_CURRENT_LIST_DIR}/BasicConveyorAndCarrier.cpp
                )
target_link_libraries(basicConveyorAndCarrier transportation)