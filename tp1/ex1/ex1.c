#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////exercice 1 //////////////

int max(int n ,int* T){
    int max = T[0];
    for (int i = 1; i < n; i++){
        if (T[i] > max){
            max = T[i];
        } 
    }
    return max;
}

int* randomiseArray(int n){
    srand(time(NULL));
    int* T = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        T[i] = rand();
        // srand(time(NULL));
    }
    return T;
}

int main(){

    int n = 900000000;
    int T1[] = {22, 25, 8, 7, 15};
    int* T2 = randomiseArray(n);

    int t1Max = max(5, T1);
    int t2Max = max(n, T2);

    printf("max of 5 sized array is %d\n", t1Max);
    printf("max of %d sized array is %d\n",n, t2Max);

    //just for the program to not close immediatly after execution
    getchar();
    /////////////////////////////////////////////////////////////

    return 0;
}

//////////////////////////////////////


