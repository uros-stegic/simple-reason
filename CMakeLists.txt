cmake_minimum_required(VERSION 2.8)

#set(CMAKE_CXX_COMPILER clang++)

project("Simple Reason")

set (_VERSION_MAJOR_ 1)
set (_VERSION_MINOR_ 0)
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

add_definitions(-std=c++11)
INCLUDE(CMakeForceCompiler)
CMAKE_FORCE_CXX_COMPILER(g++ GNU)

set(TARGET simple-reason)

include_directories(${HEADERS})
include_directories(${PROJECT_SOURCE_DIR}/include/formulae)
include_directories(${PROJECT_SOURCE_DIR}/include/transformations)
include_directories(${PROJECT_SOURCE_DIR}/include/semantics)
include_directories(${PROJECT_BINARY_DIR})

file(GLOB RESOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/formulae/*.cpp
    ${PROJECT_SOURCE_DIR}/src/transformations/*.cpp
    ${PROJECT_SOURCE_DIR}/src/semantics/*.cpp

    ${PROJECT_SOURCE_DIR}/include/formulae/*.hpp
    ${PROJECT_SOURCE_DIR}/include/transformations/*.hpp
    ${PROJECT_SOURCE_DIR}/include/semantics/*.hpp
)

add_executable(${TARGET}
    ${RESOURCES}
)

