#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <memory.h>

#include "array_header.h"

typedef struct CharArray {
    ArrayHeader header;
    char data[10];
} CharArray;

// recomended initial capacity 10
CharArray* charArrayInit(int initialCapacity){
    size_t size = sizeof(char) * initialCapacity + sizeof(ArrayHeader);
    CharArray* array = (CharArray*)malloc(size);

    if(!array){
        printf("Error allocation memory for CharArray %s::%d\n", __FILE__, __LINE__);
        exit(-1);
    }

    memset(array, 0, size);

    array->header.capacity = initialCapacity;
    array->header.elementSize = sizeof(char);
    array->header.length = 0;
    return array;
}

CharArray* charArrayInsertElement(CharArray* array, char element){
    if(array->header.length + 1 == array->header.capacity){
        array = realloc(array, array->header.capacity * array->header.elementSize * 2 + sizeof(ArrayHeader));
        if(array == NULL) {
            printf("Error reallocating array\n");
            exit(-1);
        } else {
            array->header.capacity *= 2;
        }
    }
    array->data[array->header.length++] = element;
    return array;
}

void charArratFini(CharArray* array) {
    free(array);
}

#endif