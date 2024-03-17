CXXTEST_ADD_TEST(basicTransportationGraph mainBasicTransportationGraph.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/BasicTransportationGraph.h
                    ${CMAKE_CURRENT_LIST_DIR}/BasicTransportationGraph.cpp
                )
target_link_libraries(basicTransportationGraph transportation)