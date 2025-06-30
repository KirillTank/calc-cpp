# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(calc)

#include_directories(/usr/include /libs)
#link_directories(/usr/include /libs)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++17")


file(GLOB_RECURSE SOURCES
    "src.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_custom_target(run
	COMMAND ./calc
	DEPENDS calc
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
