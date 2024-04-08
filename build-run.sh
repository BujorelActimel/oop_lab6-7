#!/bin/bash

cd build
cmake ..
make
cd ..
# clear
./build/app