#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int fila[200]; 
        
        for (int i = 0; i < n; i++) {
            fila[i] = i + 1;
        }

        int inicio = 0;
        int fim = n - 1;

        printf("Discarded cards:");

        while (fim - inicio >= 1) {
            printf(" %d", fila[inicio]);
            inicio++;

            if (fim - inicio >= 1) {
                printf(",");
            }

            int cartas = fila[inicio];
            inicio++;
            fim++;
            fila[fim] = cartas;
        }

        printf("\nRemaining card: %d\n", fila[inicio]);
    }

    return 0;
}