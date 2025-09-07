#include <stdio.h>

int main() {
    int n, i, menorValor, posicao;

    scanf("%d", &n);
    int x[n];
    int *p = x;

    for (i = 0; i < n; i++)
    {
        scanf("%d", x + i);
    }

    menorValor = *p;
    posicao = 0;

    for (i = 1; i < n; i++)
    {
        if ((*(p + i)) < menorValor)
        {
            menorValor = *(p + i);
            posicao = i;
        }
    }

    printf("O menor valor é: %d\n", menorValor);
    printf("A posição é: %d\n", posicao);
}