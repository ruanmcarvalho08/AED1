#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

char joias[MAX][101];

int comparar(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int total = 0;
    
    while (scanf("%s", joias[total]) != EOF) {
        total++;
    }
    
    qsort(joias, total, 101 * sizeof(char), comparar);
    
    int unicas = (total > 0) ? 1 : 0;
    for (int i = 1; i < total; i++) {
        if (strcmp(joias[i], joias[i-1]) != 0) {
            unicas++;
        }
    }
    
    printf("%d\n", unicas);
    
    return 0;
}