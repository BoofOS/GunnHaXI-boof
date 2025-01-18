cmake_minimum_required(VERSION 3.10)

project(boof)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(boof src/main.cpp)

include_directories(vendor/argparse)
include_directories(vendor/fmt/include)

add_subdirectory(vendor/fmt)

target_link_libraries(boof fmt::fmt)