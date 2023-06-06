set -x
gcc -Wall fuse-example.c $(pkg-config fuse --cflags --libs) -o fuse_example
