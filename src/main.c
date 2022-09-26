
//For printf
#include <stdio.h>

#include "cpy_fast.h"

int main(int argc, char *argv[]) {
	char buf[24];
	char str[] = "Hello Worlds\0\0\0\0\0\0\0";
	
	// Tests for copying of overlapping buffers
	
	void (*cpy)(void *, void *, size_t) = cpy_fast;
	
	// "Hello Worlds"
	cpy(buf, str, 14);
	printf("%s\n", buf);
	
	// Move 13 bytes foreward by 4 bytes
	// "HellHello Worlds"
	cpy(&buf[4], buf, 13);
	printf("%s\n", buf);
	
	// Move 12 bytes backward by 2 bytes
	// "HeHello Worldsds"
	cpy(&buf[2], &buf[4], 12);
	
	// Should print "HeHello Worldsds"
	printf("%s\n", buf);
	
	return 0;
}
