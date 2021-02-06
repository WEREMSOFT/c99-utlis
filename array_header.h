#ifndef __ARRAY_HEADER_H__
#define __ARRAY_HEADER_H__

#include <stdint.h>

typedef struct ArrayHeader {
    uint64_t capacity;
    uint64_t length;
    uint64_t elementSize;
} ArrayHeader;

#endif