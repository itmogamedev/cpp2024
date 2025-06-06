cmake_minimum_required(VERSION 3.30)
project(LibUsage)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibUsage main.cpp)
target_link_libraries(LibUsage ${CMAKE_SOURCE_DIR}/lib/libMath.a)