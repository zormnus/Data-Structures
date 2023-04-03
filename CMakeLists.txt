cmake_minimum_required(VERSION 3.24)
project(dsModule)

set(CMAKE_CXX_STANDARD 17)

add_library(list_lib STATIC
        DataStructures/mylist.h
        DataStructures/mylist.cpp)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE list_lib)
