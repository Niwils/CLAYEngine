CXXTEST_ADD_TEST(MainWindowDisplayTest mainMainWindowDisplayTest.cpp 
        			${CMAKE_CURRENT_LIST_DIR}/MainWindowDisplayTest.h
                    ${CMAKE_CURRENT_LIST_DIR}/MainWindowDisplayTest.cpp
                )
target_link_libraries(MainWindowDisplayTest engine ${SDL2_LIBRARIES})