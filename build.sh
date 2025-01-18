mkdir -p cmake-build-debug
cmake -G ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CXX_FLAGS="-std=c++17 -Wall -Wextra -Werror" cmake-build-debug
cmake --build cmake-build-debug
