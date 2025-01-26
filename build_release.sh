mkdir -p cmake-build-release
cd cmake-build-release
cmake -G Ninja -DCMAKE_BUILD_TYPE=release ..
cmake --build . --parallel $(( $(nproc) - 1 ))
