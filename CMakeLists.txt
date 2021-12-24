cmake_minimum_required(VERSION 3.0.0)
project(lcm_learning VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(./include)
include_directories(./lcm_types)

add_subdirectory(publisher)
add_subdirectory(subscriber)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
