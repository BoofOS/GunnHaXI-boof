cmake_minimum_required(VERSION 3.10)

project(boof)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD_REQUIRED True)
execute_process(COMMAND which clang++ OUTPUT_VARIABLE CXX_COMPILER_PATH OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND which clang OUTPUT_VARIABLE C_COMPILER_PATH OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_CXX_COMPILER ${CXX_COMPILER_PATH} CACHE STRING "C++ compiler" FORCE)
set(CMAKE_C_COMPILER ${C_COMPILER_PATH} CACHE STRING "C compiler" FORCE)
# for debug builds
set(CMAKE_C_FLAGS "-g -glldb -std=c17 -Wall -Wextra -Wpedantic -fuse-ld=lld -fPIC -fPIE")
set(CMAKE_CXX_FLAGS "-g -glldb  -std=c++17 -Wall -Wextra -Wpedantic -fuse-ld=lld -fPIC -fPIE")
set(CMAKE_EXE_LINKER_FLAGS "-fuse-ld=lld")
# for release builds
#set(CMAKE_C_FLAGS "-O3 -std=c17 -Wall -Wextra -Wpedantic -fuse-ld=lld -fPIC -fPIE")
#set(CMAKE_CXX_FLAGS "-O3 -std=c++17 -Wall -Wextra -Wpedantic -fuse-ld=lld -fPIC -fPIE")
#set(CMAKE_EXE_LINKER_FLAGS "-fuse-ld=lld")


add_executable(boof src/main.cpp src/update.cpp src/fzf_search.cpp src/install.cpp src/download.cpp src/use.cpp src/meta.cpp)

include_directories(vendor/argparse)
include_directories(vendor/fmt/include)
include_directories(vendor/luacpp)
include_directories(/usr/include/lua5.4)
include_directories(src)
include_directories(/usr/include/curl)

add_subdirectory(vendor/fmt)
add_subdirectory(vendor/luacpp)
add_compile_options(-g -glldb -Wall -Wextra -Wpedantic -fuse-ld=lld -fPIC -fPIE)
find_library(curl curl REQUIRED)
target_link_libraries(boof fmt luacpp curl)