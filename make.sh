#!/bin/bash
set -e
cd build
if [[ $1 == "clean" ]]
then
    clear
    rm * -r
fi
if [[ $1 == "run" ]]
then
    ./example
else
    cmake ..
    make -j4
    ./example
fi