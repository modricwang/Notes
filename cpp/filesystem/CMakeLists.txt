cmake_minimum_required(VERSION 3.9)
project(test_Cpp17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
add_library(stdc++fs UNKNOWN IMPORTED)
set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/gcc/x86_64-linux-gnu/7/libstdc++fs.a")

add_executable(test_Cpp17 main.cpp)
target_link_libraries(${PROJECT_NAME} stdc++fs)