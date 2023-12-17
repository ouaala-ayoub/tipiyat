#include <stdio.h>
#include "array_utils.h"

void printArray(int size,int* T){
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", T[i]);
        if(i != size - 1){
            printf(" ,");
        }
    }
    printf("]");
}