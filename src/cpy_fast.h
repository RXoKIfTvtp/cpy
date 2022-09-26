
#ifndef CPY_FAST_H
#define CPY_FAST_H

// For size_t and NULL
#include <stddef.h>

#include "types.h"

/**
 * A function for copying data between locations.
 * Source and destination buffers may overlap or be the same.
 * Contains some optimizations for memory aligned data.
**/
void cpy_fast(void *dst, void *src, size_t n);

#endif /* CPY_FAST_H */
