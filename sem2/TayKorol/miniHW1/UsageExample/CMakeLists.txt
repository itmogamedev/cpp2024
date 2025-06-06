cmake_minimum_required(VERSION 3.10)
project(UsageExample)

set(CMAKE_CXX_STANDARD 20)


include_directories(include)

link_directories(lib)

add_executable(UsageExample src/main.cpp)

target_link_libraries(UsageExample Statistics)