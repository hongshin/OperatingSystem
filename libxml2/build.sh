#!/bin/bash

set -x
./autogen.sh
CC='clang' CFLAGS="-g -fsanitize=address -fsanitize-coverage=edge,trace-pc-guard" ./configure --enable-static --disable-shared
make -j4
