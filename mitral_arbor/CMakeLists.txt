cmake_minimum_required(VERSION 3.9)
project(arbor-mitral LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)

find_package(arbor REQUIRED)
add_executable(mitral mitral.cpp)

target_link_libraries(mitral PRIVATE arbor::arbor arbor::arborenv)
target_include_directories(mitral PRIVATE include)

set_target_properties(mitral PROPERTIES OUTPUT_NAME arbor-mitral)
