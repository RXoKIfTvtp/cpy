
#ifndef CPY_MINI_H
#define CPY_MINI_H

// For size_t and NULL
#include <stddef.h>

#include "types.h"

/**
 * A small function for copying data between locations.
 * Source and destination buffers may overlap or be the same.
 * Does not contain optimizations for memory aligned data.
**/
void cpy_mini(void *dst, void *src, size_t n);

#endif /* CPY_MINI_H */
