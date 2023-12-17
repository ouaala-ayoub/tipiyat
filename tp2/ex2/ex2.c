#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//tableaux

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

int deleteIndexed(int *T, int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("Index out of bounds exception\n");
        return 0;
    }
    for (int i = index; i < *size - 1; ++i) {
        T[i] = T[i + 1];
    }
    *size = *size - 1;
    return 1;
}
void inverseArray(int T[], int size) {
    int debut = 0;
    int fin = size - 1;

    while (debut < fin) {

        int temp = T[debut];
        T[debut] = T[fin];
        T[fin] = temp;

        debut++;
        fin--;
    }
}

int* joinArrays(int* T, int sizeOfT, int* A, int sizeOfA){
    int i = 0, j = 0, k = 0;

    int totalSize = sizeOfT + sizeOfT;
    int* result = malloc(totalSize * sizeof(int));

    while (i < sizeOfT && j < sizeOfA){
         result[k++] = (T[i] <= A[j]) ? T[i++] : A[j++];
    }

    while (i < sizeOfT) {
        result[k++] = T[i++];
    }

    while (j < sizeOfA) {
        result[k++] = A[j++];
    }
    return result;
}

//matrices

//initialisation
void initMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 10; // Valeurs aléatoires entre 0 et 9
        }
    }
}

//affichage
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// additionner
void addMatrices(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// multiplier
void multiplyMatrices(int rows1, int cols1, int m1[rows1][cols1], int rows2, int cols2, int m2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int T[] = { 1, 2, 3, 8, 15, 7, 10, 7};
    int size = sizeof(T) / sizeof(T[0]);

    int T1[] = { 1, 5, 10, 45};
    int T2[] = {3, 3, 4, 15 ,70};

    int size1 = sizeof(T1) / sizeof(T1[0]);
    int size2 = sizeof(T2) / sizeof(T2[0]);

    //supprimer
    // printf("avant\n");
    // printArray(size, T);
    // deleteIndexed(T, &size, 4);
    // printf("apres suppression de l'element de d'indice 4\n");
    // printArray(size, T);

    //inverser
    // printf("avant\n");
    // printArray(size, T);
    // printf("apres\n");
    // inverseArray(T, size);
    // printArray(size, T);

    //fusion
    // printf("T1 = ");
    // printArray(size1, T1);
    // printf("T2 = ");
    // printArray(size2, T2);
    // int *T3 = joinArrays(T1, size1,T2, size2);
    // printf("fusion => ");
    // printArray(size1 + size2, T3);

    //partie matrice
    int matrix1[3][3] = {{1, 1, 0}, {2, 1, 0}, {5, 0, 1}};
    int matrix2[3][3] = {{1, 2, 0}, {0, 1, 1}, {0, 8, 0}};
    int randomInitiated[3][3];
    int multipMatrix[3][3];
    int additionMatrix[3][3];

    multiplyMatrices(3, 3, matrix1, 3, 3, matrix2, multipMatrix);
    addMatrices(3, 3, matrix1, matrix2, additionMatrix);

    //aleatoire
    printf("matrices de valeurs aleatoires entre 0 et 9 : \n");
    for (int i = 0; i < 3; i++){
        initMatrix(3, 3, randomInitiated);
        printMatrix(3, 3, randomInitiated);
        printf("\n");
    }

    printf("addition\n");

    //addition
    printMatrix(3, 3, matrix1);
    printf("\t+ \n");
    printMatrix(3, 3, matrix2);
    printf(" \t= \n");
    printMatrix(3, 3, additionMatrix);

    printf("multiplication\n");

    // //multiplication
    printMatrix(3, 3, matrix1);
    printf(" \tx \n");
    printMatrix(3, 3, matrix2);
    printf(" \t= \n");
    printMatrix(3, 3, multipMatrix);

    return 0;
}
