#include <stdio.h>
#include <stdlib.h>

int cherche_Dich_lt(int A[], int n, int cle) {
    int d = 0, f = n - 1, i=0;
    int trouve = 0;

    while (d <= f && !trouve) {
        i = (d + f) / 2;

        if (A[i] == cle) 
            trouve = 1;
         else 
            if (A[i] < cle) 
                d = i + 1;
             else 
                f = i - 1;
    }

    return trouve ? i : -1; 
}

int main(){
    int array[] = {1, 7, 8, 9, 12, 15, 18, 22, 30, 31};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 30;

    int result = cherche_Dich_lt(array, size, key);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}
