#!/bin/bash
set -e
#if $1 
cd build
cmake ..
make
./example