#include <stdio.h>
#include <stdlib.h>

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

void switchValues(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int triAbulle(int size,int* T){
    int count = 0;
    for (int i = 0; i < size; i++){
        for (int j = size - 1; j > i; j--){
            if (T[j] < T[j-1]) {
                count++;
                switchValues(T + j, T + j -1);
            }
        }
    }
    return count;
}



int main(){
    int n = 10;
    int T[] = {1, 5, 2, 3, 15, 0, 22, 4, 12, 7};
    printf("avant\n");
    printArray(n, T);
    int count = triAbulle(n, T);
    printf("apres\n");
    printArray(n, T);
    printf("nombre de comparaison effectuees %d", count);
    return 0;
}
