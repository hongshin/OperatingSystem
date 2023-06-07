set -x
gcc -Wall fuse-example.c $(pkg-config fuse json-c --cflags --libs) -o fuse_example
