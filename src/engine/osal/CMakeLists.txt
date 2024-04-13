add_library(osal ${CMAKE_CURRENT_LIST_DIR})
target_sources(osal
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/common/IOsalSys.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/sdl/OsalSys.cpp"
)

target_include_directories(osal PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/common/"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/"
        ${SDL2_INCLUDE_DIRS})
target_link_libraries(osal ${SDL2_LIBRARY})