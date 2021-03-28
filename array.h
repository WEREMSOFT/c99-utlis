#ifndef __UNIVERSAL_ARRAY_H__
#define __UNIVERSAL_ARRAY_H__

#include "array_header.h"
#include <stdlib.h>
#include <string.h>

typedef struct Array {
    ArrayHeader header;
    char data[1];
} Array;

// recomended initial capacity 10
Array* arrayCreate(int initialCapacity, size_t elementSize){
    size_t size = elementSize * initialCapacity + sizeof(ArrayHeader);
    Array* array = (Array*)malloc(size);

    if(!array){
        printf("Error allocation memory for UniversalArray %s::%d\n", __FILE__, __LINE__);
        exit(-1);
    }

    memset(array, 0, size);

    array->header.capacity = initialCapacity;
    array->header.elementSize = elementSize;
    array->header.length = 0;
    return array;
}

void arrayInsertElement(Array** this, void *element){
    if((*this)->header.length + 1 == (*this)->header.capacity){
        *this = realloc(*this, (*this)->header.capacity * (*this)->header.elementSize * 2 + sizeof(ArrayHeader));
        if(*this == NULL) {
            printf("Error reallocating array\n");
            exit(-1);
        } else {
            (*this)->header.capacity *= 2;
        }
    }

    memcpy(&(**this).data[(*this)->header.elementSize * (*this)->header.length++], element, (**this).header.elementSize);
}

void universalArratFini(Array* array) {
    free(array);
}

#endif
