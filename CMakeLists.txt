cmake_minimum_required(VERSION 3.0)

project(snackis)

set(CMAKE_CXX_COMPILER g++)

add_compile_options(-std=c++17 -Wall -Werror -O2 -g)

file(GLOB_RECURSE sources src/snackis/*.cpp)

add_executable(snackis ${sources} src/main.cpp)
target_include_directories(snackis PUBLIC src/)
target_link_libraries(snackis snabl pthread)

install(FILES build/snackis DESTINATION bin PERMISSIONS WORLD_EXECUTE)
