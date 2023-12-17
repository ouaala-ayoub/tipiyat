#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printArray(int size,long long* T){
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%lld", T[i]);
        if(i != size - 1){
            printf(" ,");
        }
    }
    printf("]\n");
}

long long *firstNTerms(int n) {
    // Allocate an array to store the first n terms
    long long *result = (long long *)malloc(n * sizeof(long long));

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Base case: u0 = 1
    result[0] = 1;

    for (int i = 1; i < n; ++i) {
        // un+1 = 3un^2 + 2un + 1
        result[i] = 3 * result[i - 1] * result[i - 1] + 2 * result[i - 1] + 1;
    }

    return result;
}

void showFirstNTerms(int n){
    long long *result = firstNTerms(n);
    printArray(n,result);
}

int main(){
    int n = 5;
    printf("premier %d termes : ", n);
    showFirstNTerms(n);
    return 0;
}
