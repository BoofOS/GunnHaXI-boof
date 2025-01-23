mkdir -p cmake-build-debug
cd cmake-build-debug
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CXX_FLAGS="-std=c++17 -Wall -Wextra -Wpedantic" ..
cmake --build .
