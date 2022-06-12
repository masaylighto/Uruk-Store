project(UrukStore)
cmake_minimum_required(VERSION 3.18)
find_package(PkgConfig REQUIRED)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)
#set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_BUILD_TYPE Debug)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set( SOURCE_FILES  "Source/Helper/FileMethod.cpp"  "Source/Database/SqliteCurd.cpp" "Source/Helper/ShellMethod.cpp"  "Source/Helper/StringMethod.cpp" "Source/main.cpp"  "Source/Base/Component.cpp" "Source/Component/AppBox.cpp" "Source/Base/Page.cpp"  "Source/Base/Window.cpp" "Source/Helper/Apt.cpp" "Source/Helper/GtkAutoComplete.cpp" "Source/Pages/HomePage.cpp" "Source/Pages/MainWindow.cpp" )
add_executable(UrukStore ${SOURCE_FILES})
target_link_libraries(UrukStore PRIVATE Threads::Threads)
link_directories(    ${GTKMM_LIBRARY_DIRS}   "/usr/lib/x86_64-linux-gnu/")
target_link_libraries(UrukStore PRIVATE libsqlite3.so)
include_directories("Headers/" "/usr/include/" ${GTKMM_INCLUDE_DIRS})






target_link_libraries(UrukStore PRIVATE ${GTKMM_LIBRARIES})
