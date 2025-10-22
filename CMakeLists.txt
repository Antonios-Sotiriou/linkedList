# Minimum CMake verion.
cmake_minimum_required(VERSION 3.20)

# Starting Project.
project(linkedList VERSION 1.0)

set(CMAKE_C_STANDARD)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)

add_executable(${PROJECT_NAME} "linked_list.c" )

# add directories to compiler include path.  ####################################################
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}")
# add directories to compiler include path.  ####################################################


