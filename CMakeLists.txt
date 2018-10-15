cmake_minimum_required(VERSION 3.0)

project(snackis)

set(CMAKE_CXX_COMPILER g++)

add_compile_options(-std=c++17 -Wall -Werror -O2 -g)

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

file(GLOB_RECURSE src src/snackis/*.cpp)

add_executable(snackis ${src})
target_include_directories(snackis PUBLIC src/)
target_link_libraries(snackis snabl pthread ${wxWidgets_LIBRARIES})

install(FILES build/snackis DESTINATION bin PERMISSIONS WORLD_EXECUTE)
