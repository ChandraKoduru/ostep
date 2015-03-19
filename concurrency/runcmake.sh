#! /bin/bash
cd _build
cmake .. -DCMAKE_INSTALL_PREFIX=../_install
make
make install
_install/bin/myapp
cd ..
