#!/bin/sh

# /bin/rm *~

/bin/rm -r NPR-GP
cd zlib
make clean
/bin/rm -f ._*
cd ..
cd libpng
make clean
/bin/rm -f ._*
cd ..
cd RMITGP.1.5
make clean
/bin/rm -f ._*
cd ..
cd src_108
make clean
/bin/rm -f ._*
cd ..

/bin/echo "Now tar the directory"



