#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * multichar(char *s, int n){
    // printf("length of s is %d", strlen(s));
    int resultLength = strlen(s) * n;
    char* result = malloc(resultLength + 1);
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(result, '\0', resultLength + 1);
    for (int i = 0; i < strlen(s); i++){
        for (int j = 0;j < n; j++){
            result[j + i * n] = s[strlen(s) - 1 - i];
        }
    }
    return result;
}

int main(){
    //change this value to test
    char *s = "ENSA";
    char *res = multichar(s, 5);
    printf("avant \t => %s\n", s);
    printf("apres \t => %s", res);
    free(res);
    return 0;
}
