CXXTEST_ADD_TEST(objListTest mainObjListTest.cpp 
                    ${CMAKE_CURRENT_LIST_DIR}/ObjListTest.h ${CMAKE_CURRENT_LIST_DIR}/ObjListTest.cpp)
	target_link_libraries(objListTest engine)