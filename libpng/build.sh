#!/bin/bash

cd libpng && export CFLAGS="-g -fsanitize=memory" LDFLAGS="-fsanitize=memory" CC=clang
./configure
make -j$npoc

gcc -o test_pngfix test_pngfix.c
