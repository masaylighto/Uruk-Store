project(UrukStore)
cmake_minimum_required(VERSION 3.18)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
set( SOURCE_FILES "Source/main.cpp"  "Source/Base/Component.cpp" "Source/Base/Page.cpp" "Source/Base/Window.cpp" "Source/Helper/Variety.cpp" "Source/Pages/MainWindow.cpp" "Source/Helper/Apt.cpp")
add_executable(UrukStore ${SOURCE_FILES})
link_directories(    ${GTKMM_LIBRARY_DIRS}  )

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(UrukStore PRIVATE ${GTKMM_INCLUDE_DIRS})

target_link_libraries(UrukStore PRIVATE ${GTKMM_LIBRARIES})
