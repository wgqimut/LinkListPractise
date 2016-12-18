cmake_minimum_required(VERSION 3.6)
project(justp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MyStack.h MyLinkList.h LinkListProblem.cpp LinkListProblem.h)
add_library(justp_lib LinkListProblem.cpp)
add_executable(justp main.cpp)
target_link_libraries(justp justp_lib)
