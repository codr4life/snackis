cmake_minimum_required(VERSION 3.0)

project(snackis)

set(CMAKE_CXX_COMPILER g++)

add_compile_options(-std=c++17 -Wall -Werror -O2 -g)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

file(GLOB_RECURSE src src/snackis/*.cpp)

add_executable(snackis ${src} src/main.cpp)
target_include_directories(snackis PUBLIC src/ ${GTK3_INCLUDE_DIRS})
target_link_libraries(snackis snabl sqlite3 pthread ${GTK3_LIBRARIES})

install(FILES build/snackis DESTINATION bin PERMISSIONS WORLD_EXECUTE)
