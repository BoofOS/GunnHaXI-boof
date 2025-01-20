cmake_minimum_required(VERSION 3.10)

project(boof)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(boof src/main.cpp)

include_directories(vendor/argparse)
include_directories(vendor/fmt/include)
include_directories(vendor/luacpp)
include_directories(/usr/include/lua5.4)

add_subdirectory(vendor/fmt)
add_subdirectory(vendor/luacpp)

target_link_libraries(boof fmt luacpp)