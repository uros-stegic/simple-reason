cmake_minimum_required(VERSION 2.8)

project("Simple Reason")

set (_VERSION_MAJOR_ 1)
set (_VERSION_MINOR_ 0)
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

set(TARGET simple-reason)
set(HEADERS ${PROJECT_SOURCE_DIR}/include)
set(SOURCES ${PROJECT_SOURCE_DIR}/src)

include_directories(${HEADERS})
include_directories(${PROJECT_BINARY_DIR})

file(GLOB RESOURCES
    ${SOURCES}/*.cpp
    ${HEADERS}/*.hpp
)

add_executable(${TARGET}
    ${RESOURCES}
)

