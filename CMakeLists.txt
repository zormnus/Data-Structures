cmake_minimum_required(VERSION 3.24)
project(dsModule)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS system unit_test_framework REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(STATUS "Boost NOT Found !")
endif(Boost_FOUND)

add_executable(${PROJECT_NAME} Two-linked_list/two_linked_list.h
        One-linked_list/one_linked_list.h
        Dynamic_array/DArray.h main.cpp main.cpp Dynamic_array/DArray.h One-linked_list/one_linked_list.cpp Two-linked_list/two_linked_list.cpp Dynamic_array/DArray.cpp)

target_link_libraries(${PROJECT_NAME} Boost::system Boost::unit_test_framework)