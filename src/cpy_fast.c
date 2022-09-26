
#include "cpy_fast.h"

// For uintptr_t
#include <stdint.h>
// Pointer, just easier to read
#define ptr_t	uintptr_t
// uint_t is defined in types.h
#define op_t uint_t

void cpy_fast(void *dst, void *src, size_t n) {
	if (dst == NULL || src == NULL) {
		return;
	}
	size_t i;
	
	if (src < dst && dst < src + n) {
		// Backward copy
		size_t words = 0;
		size_t bytes = n;
		ubyte_t *d = (ubyte_t *)dst;
		ubyte_t *s = (ubyte_t *)src;
		
		if (
			(ptr_t)dst % sizeof(op_t) == 0 &&
			(ptr_t)src % sizeof(op_t) == 0
		) {
			words = n / sizeof(op_t);
			size_t t = words * sizeof(op_t);
			bytes -= t;
			d += t;
			s += t;
		}
		
		// Copy unalligned bytes
		i = bytes;
		while (i-- > 0) {
			d[i] = s[i];
		}
		
		// Copy words if memory is alligned
		op_t *_d = (op_t *)dst;
		const op_t *_s = (op_t *)src;
		
		i = words;
		while (i-- > 0) {
			_d[i] = _s[i];
		}
	} else {
		// Foreward copy
		void *_dst = (void *)dst;
		void *_src = (void *)src;
		size_t _len = n;
		
		// Copy words if memory is alligned
		if (
			(ptr_t)_dst % sizeof(op_t) == 0 &&
			(ptr_t)_src % sizeof(op_t) == 0
		) {
			size_t words = _len / sizeof(op_t);
			
			op_t *d = (op_t *)_dst;
			op_t *s = (op_t *)_src;
			
			for (i = 0; i < words; i++) {
				d[i] = s[i];
			}
			
			size_t bytes = words * sizeof(op_t);
			_dst = d + bytes;
			_src = s + bytes;
			_len -= bytes;
		}
		
		// Copy unalligned bytes
		ubyte_t *d = (ubyte_t *)_dst;
		const ubyte_t *s = (ubyte_t *)_src;
		
		for (i = 0; i < _len; i++) {
			d[i] = s[i];
		}
	}
}

// Free these in case another modules wants
// to use them differently
#undef ptr_t
#undef op_t
