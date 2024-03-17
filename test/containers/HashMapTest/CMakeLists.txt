CXXTEST_ADD_TEST(basicHashMapTest mainBasicHashMapTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/BasicHashMapTest.h
        ${CMAKE_CURRENT_LIST_DIR}/BasicHashMapTest.cpp
                )
target_link_libraries(basicHashMapTest engine)