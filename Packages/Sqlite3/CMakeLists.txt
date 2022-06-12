project(Sqlite3 C)
cmake_minimum_required(VERSION 3.18)
find_package(PkgConfig REQUIRED)
#set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)
set(SOURCE_FILES  "shell.c"  "sqlite3.c")
add_library(Sqlite3 ${SOURCE_FILES})


