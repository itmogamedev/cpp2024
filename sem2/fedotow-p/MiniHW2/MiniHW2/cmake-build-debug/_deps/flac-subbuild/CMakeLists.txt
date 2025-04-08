# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.30.5)

# Reject any attempt to use a toolchain file. We must not use one because
# we could be downloading it here. If the CMAKE_TOOLCHAIN_FILE environment
# variable is set, the cache variable will have been initialized from it.
unset(CMAKE_TOOLCHAIN_FILE CACHE)
unset(ENV{CMAKE_TOOLCHAIN_FILE})

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(flac-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[C:/Program Files/Git/cmd/git.exe]==])
set(GIT_VERSION_STRING [==[2.49.0.windows.1]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[C:/Program Files/Git/cmd/git.exe;2.49.0.windows.1]==]
)


include(ExternalProject)
ExternalProject_Add(flac-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/xiph/flac.git" "EXTERNALPROJECT_INTERNAL_ARGUMENT_SEPARATOR" "GIT_TAG" "1.4.3" "GIT_SHALLOW" "ON" "PATCH_COMMAND" "G:/CLion 2024.3/bin/cmake/win/x64/bin/cmake.exe" "-DFLAC_DIR=C:/Users/Пашок/CLionProjects/MiniHW2/cmake-build-debug/_deps/flac-src" "-P" "C:/Users/Пашок/CLionProjects/MiniHW2/cmake-build-debug/_deps/sfml-src/tools/flac/PatchFLAC.cmake"
                    SOURCE_DIR          "C:/Users/Пашок/CLionProjects/MiniHW2/cmake-build-debug/_deps/flac-src"
                    BINARY_DIR          "C:/Users/Пашок/CLionProjects/MiniHW2/cmake-build-debug/_deps/flac-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


