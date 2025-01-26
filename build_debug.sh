mkdir -p cmake-build-debug
cd cmake-build-debug
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --parallel $(( $(nproc) - 1 ))
