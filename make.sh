#!/bin/bash
set -e
cd build
if [[ $1 == "clean" ]]
then
    rm * -r
fi
cmake ..
make -j4
./example