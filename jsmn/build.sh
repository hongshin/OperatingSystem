#!/bin/bash

set -x

export ASAN_OPTIONS=detect_leaks=0:halt_on_error=1
CC="clang" CFLAGS="-O0 -g -fsanitize=address" LDFLAGS="-fsanitize=address" make jsondump
