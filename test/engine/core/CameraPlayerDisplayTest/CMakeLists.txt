CXXTEST_ADD_TEST(CameraPlayerDisplayTest mainCameraPlayerDisplayTest.cpp 
        			${CMAKE_CURRENT_LIST_DIR}/CameraPlayerDisplayTest.h
                    ${CMAKE_CURRENT_LIST_DIR}/CameraPlayerDisplayTest.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/ConcreteGameModel.h
                    ${CMAKE_CURRENT_LIST_DIR}/ConcreteGameModel.cpp
                )
target_link_libraries(CameraPlayerDisplayTest engine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})