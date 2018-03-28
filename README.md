# Memory-Test
simple memory allocation test, written to check for memory allocation problem on AIX -> AIX has a limited size of memory allocation for one chunk (256? MB per CPU), however for version higher than 3.? you can tell the ld to increase that

gcc -lm -o memtest memtest.c

Also prints out some basic info on byte size of various types (i.e. float, double, int, long, etc)
