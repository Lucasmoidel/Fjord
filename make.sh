#!/bin/bash
set -e
cd build
if [ $1 == "clean" ]
then
    rm * -r
cmake ..
make
./example