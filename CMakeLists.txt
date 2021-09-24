cmake_minimum_required (VERSION 3.16)

project (myprogram)

set (CMAKE_BUILD_TYPE "Release")

add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/pybind11/ py11)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/val3dity/thirdparty/nlohmann-json)

pybind11_add_module(val3ditypy src/val3ditypy.cpp)

add_subdirectory (${CMAKE_SOURCE_DIR}/thirdparty/val3dity/ val3)

target_link_libraries (val3ditypy LINK_PUBLIC val3dity)