# CPY

cpy_fast and cpy_mini are functions for copying overlapping buffers in C. They are very similar to the standard C library memcpy and memmove. An example use would be if you need to slide a part of a buffer forward or backward. These functions may overwrite parts of buffers that over lap.

cpy_fast copies multiple bytes at a time if they are properly aligned in memory, otherwise it copies byte by byte.
cpy_mini always copies one byte at a time and is intended for use in micro-controllers.


