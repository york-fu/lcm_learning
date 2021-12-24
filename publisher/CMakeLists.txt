cmake_minimum_required(VERSION 3.0.0)
project(publisher VERSION 0.1.0)

find_package(lcm REQUIRED)
include_directories(./)

add_executable(${PROJECT_NAME} ./publisher.cpp)
target_link_libraries(${PROJECT_NAME} lcm)
