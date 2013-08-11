#!/bin/sh

echo "***************************************************************"
echo "*                                                             *"
echo "*   For Sun0S source the file set-SunOS-Environment.sh first  *"
echo "*                                                             *"
echo "***************************************************************"

# This script is used to compile the entire project.

# Compiles src.1.4, zlib and libpng as static libraries
cd zlib
echo "************************************"
echo "*                                  *"
echo "*   Building zlib static library   *"
echo "*                                  *"
echo "************************************"
make clean
make
cd ..
# The libpng part of this script is completely commented out because of
# compatability problems.
cd libpng
echo "**************************************"
echo "*                                    *"
echo "*   Building libpng static library   *"
echo "*                                    *"
echo "**************************************"
make clean
make
#echo "### Type: ./pngtest to test the libraries"
cd ..
cd RMITGP.1.5
echo "***************************************"
echo "*                                     *"
echo "*   Building src.1.5 static library   *"
echo "*                                     *"
echo "***************************************"
make clean
make depend
make
cd ..
cd src_108
echo "***************************************"
echo "*                                     *"
echo "*   Building NPR-GP executable        *"
echo "*                                     *"
echo "***************************************"
make clean
make depend
make
cp NPR-GP ..
cd ..


