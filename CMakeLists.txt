cmake_minimum_required (VERSION 3.29.2)
project (FactoryBuilder)

option(BUILD_TESTS "-DBUILD_TESTS - Build test programs" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/tools/cmake/")
set(CMAKE_CXX_FLAGS "-std=c++0x")
set(CMAKE_BUILD_TYPE Debug)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

message(STATUS "SDL2_INCLUDE_DIRS={${SDL2_INCLUDE_DIRS}}")


#find_library(SDL2_IMAGE REQUIRED)
#include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

#message(STATUS "SDL2_IMAGE_INCLUDE_DIRS={${SDL2_IMAGE_INCLUDE_DIRS}}")

include_directories(src/engine/containers
					src/engine/core
					src/engine/graph
					src/engine/osal
					src/engine/production
					src/engine/transportation
					src/engine/world
					src/common
					${SDL2_INCLUDE_DIRS})
					# ${SDL2_IMAGE_INCLUDE_DIRS})

include(src/engine/CMakeLists.txt)

if(BUILD_TESTS)
	set(CMAKE_BUILD_TYPE Debug)

	find_package(CxxTest)
	if(CXXTEST_FOUND)
		enable_testing()
		include_directories(${CXXTEST_INCLUDE_DIR}
							src/engine/containers
							src/engine/core
							src/engine/graph
							src/engine/osal
							src/engine/production
							src/engine/transportation
							src/engine/world
							src/common
							${SDL2_INCLUDE_DIRS})
							#${SDL2_IMAGE_INCLUDE_DIRS})
		include(test/CMakeLists.txt)
	endif()
else()
	add_executable(${PROJECT_NAME} src/game/FactoryBuilder.cpp)
	target_link_libraries(${PROJECT_NAME} engine)
endif()


