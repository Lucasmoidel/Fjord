#!/bin/bash
cd build
rm * -r
cmake ..
make
./example