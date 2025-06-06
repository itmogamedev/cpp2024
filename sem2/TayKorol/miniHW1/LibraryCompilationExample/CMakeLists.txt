cmake_minimum_required(VERSION 3.28.1)
project(LibraryCompilationExample)

set(CMAKE_CXX_STANDARD 20)
# сборка статической библиотеки
add_library(Statistics STATIC static_lib_example/double_statistics.cpp)
target_include_directories(Statistics PUBLIC /static_lib_example)


# использование статической библиотеки
add_executable(compilation_example main.cpp
        header_only_lib_example/statistics.h)
target_link_libraries(compilation_example Statistics)