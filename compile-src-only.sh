#!/bin/sh

# This script recompiles the src/ code.

#clear
cd src_108/
make clean
make depend
make
cp NPR-GP ../
cd ..

