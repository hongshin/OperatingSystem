### Libpng

Libpng is a library program for handling PNG image files. This project has a bug that reads a uninitialized variable. A failure occurs as a utility program ``pngfix`` is executed with a specific PNG file. For delta-debugging purpose, we provide a wrapper program ``test_pngfix`` which receives a PNG file via standard input and runs ``pngfile`` with the given image.

You can build this project by running ``./build.sh``. You can reproduce the crash by running ``./libpng/test_pngfix < crash.png``. The crash message will show `` MemorySanitizer: use-of-uninitialized-value``.
