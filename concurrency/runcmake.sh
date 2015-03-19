#! /bin/bash
cd _build
cmake -G "Unix Makefiles" .. -DCMAKE_INSTALL_PREFIX=../_install
make
make install
../_install/bin/t0
../_install/bin/tapi
cd ..
