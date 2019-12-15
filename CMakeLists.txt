cmake_minimum_required (VERSION 3.1)
project (FactoryBuilder)

option(BUILD_TESTS "-DBUILD_TESTS - Build test programs" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/tools/cmake/")
set(CMAKE_CXX_FLAGS "-std=c++0x")
include_directories(src/engine/containers
					src/engine/graph
					src/common)

add_executable(${PROJECT_NAME} src/game/FactoryBuilder.cpp)
include(src/engine/CMakeLists.txt)

if(BUILD_TESTS)
	set(CMAKE_BUILD_TYPE Debug)

	find_package(CxxTest)
	if(CXXTEST_FOUND)
		enable_testing()
		include_directories(${CXXTEST_INCLUDE_DIR} src/engine/containers src/engine/graph src/common)
		include(test/CMakeLists.txt)
	endif()
endif()

target_link_libraries(${PROJECT_NAME} engine)
