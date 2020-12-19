CXXTEST_ADD_TEST(basicProductionTest mainBasicProductionTest.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/TestableConcreteEdge.h
                    ${CMAKE_CURRENT_LIST_DIR}/TestableConcreteEdge.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/TestableConcreteNode.h
                    ${CMAKE_CURRENT_LIST_DIR}/TestableConcreteNode.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/BasicNodeEdgeNodeTest.h
                    ${CMAKE_CURRENT_LIST_DIR}/BasicNodeEdgeNodeTest.cpp
                )
target_link_libraries(basicProductionTest engine)