#include <stdlib.h>
#include <stdio.h>

#define NB_MAX 10
void printArray(int size,int* T){
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", T[i]);
        if(i != size - 1){
            printf(" ,");
        }
    }
    printf("]\n");
}

int insertIndexed(int *T, int size, int index, int toInsert) {
    if (index > size || size >= NB_MAX){
        return 0;
    }

    for (int i = size - 1; i >= index; i--){
        T[i+1] = T[i];
    }
    T[index] = toInsert;

    return 1;
}

int main(){
    int T[] = {1, 2, 3, 5, 78};
    int size = sizeof(T) / sizeof(T[0]);

    printf("avant\n");
    printArray(size, T);

    printf("insertion de 15 dans l'indice 2\n");

    int inserted = insertIndexed(T, size, 2, 15);
    if (inserted){
        size++;
        printArray(size, T);
    } else {
        printf("Element not inserted\n");
    }
    
    return 0;
}
