project(UrukStore)
cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig REQUIRED)
#set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Debug)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
set( SOURCE_FILES  "Source/Helper/FileMethod.cpp"  "Source/Database/SqliteCurd.cpp" "Source/Helper/ShellMethod.cpp"  "Source/Helper/StringMethod.cpp" "Source/main.cpp"  "Source/Base/Component.cpp" "Source/Component/AppBox.cpp" "Source/Base/Page.cpp"  "Source/Base/Window.cpp" "Source/Helper/Apt.cpp" "Source/Helper/GtkAutoComplete.cpp" "Source/Pages/HomePage.cpp" "Source/Pages/MainWindow.cpp" )
add_executable(UrukStore ${SOURCE_FILES})
link_directories(    ${GTKMM_LIBRARY_DIRS}  )
#set(CMAKE_CXX_FLAGS_RELEASE "-O3")
include_directories("Headers/")
include_directories("Packages/Sqlite3" )
# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(UrukStore PRIVATE ${GTKMM_INCLUDE_DIRS})

add_subdirectory("Packages/Sqlite3/")
include_directories("Packages/Sqlite3" )

target_link_libraries(UrukStore PRIVATE ${GTKMM_LIBRARIES})
