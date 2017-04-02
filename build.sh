#!/usr/bin/sh

mkdir -p build
cd build
cmake ..
make
echo "================ Executing program ================"
time ./simple-reason
echo "==================================================="
