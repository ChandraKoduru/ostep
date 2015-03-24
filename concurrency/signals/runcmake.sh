#! /bin/bash
cd _build
cmake -G "Unix Makefiles" .. -DCMAKE_INSTALL_PREFIX=../_install
make
make install
cd ..
