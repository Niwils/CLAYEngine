add_library(world ${CMAKE_CURRENT_LIST_DIR})
target_sources(world
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/ITile.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/WorldElement.cpp"
)

target_include_directories(world PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/common/"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/"
        ${SDL2_INCLUDE_DIRS})
target_link_libraries(osal ${SDL2_LIBRARIES})