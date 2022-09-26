
#include "cpy_mini.h"

void cpy_mini(void *dst, void *src, size_t n) {
	if (dst == NULL || src == NULL) {
		return;
	}
	ubyte_t *d = (ubyte_t *)dst;
	ubyte_t *s = (ubyte_t *)src;
	
	if (src < dst && dst < src + n) {
		// Backward copy
		d += n;
		s += n;
		while (n--) {
			*--d = *--s;
		}
	} else {
		// Foreward copy
		while (n--) {
			*d++ = *s++;
		}
	}
}
