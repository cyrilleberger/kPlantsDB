cmake_minimum_required(VERSION 2.6)
project(kplantsdb)

find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Test REQUIRED)

add_definitions(-std=c++11)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(kPlantsDB)
add_subdirectory(examples)