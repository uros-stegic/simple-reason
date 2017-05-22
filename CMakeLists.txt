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

# Flex&Bison configuration
find_package (FLEX 2.5.35)
find_package (BISON 2.4.1)

BISON_TARGET(MyParser parser/parser.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cpp VERBOSE)
FLEX_TARGET(MyScanner parser/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

set(TARGET simple-reason)

include_directories ("${CMAKE_CURRENT_BINARY_DIR}")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/include/formulae")
include_directories ("${PROJECT_SOURCE_DIR}/include/transformations")
include_directories ("${PROJECT_SOURCE_DIR}/include/semantics")
include_directories ("${PROJECT_BINARY_DIR}")

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
	${FLEX_MyScanner_OUTPUTS}
	${BISON_MyParser_OUTPUTS}
    ${RESOURCES}
)

