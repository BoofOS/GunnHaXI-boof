mkdir -p cmake-build-debug
cd cmake-build-debug
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS="-g -glldb  -std=c++17 -Wall -Wextra -Wpedantic" ..
cmake --build . --parallel $(( $(nproc) - 1 ))
