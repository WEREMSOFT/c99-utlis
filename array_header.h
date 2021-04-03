#ifndef __ARRAY_HEADER_H__
#define __ARRAY_HEADER_H__

#include <stdint.h>

typedef struct ArrayHeader {
    int capacity;
    int length;
    int elementSize;
    int allocatedBytes;
} ArrayHeader;

#endif