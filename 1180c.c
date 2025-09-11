#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, menorValor, posicao;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    // Alocação dinâmica
    vetor = (int *) malloc(N * sizeof(int)); // vetor = (ponteiro de inteiro) malloc(tamanho do vetor * bytes de um inteiro (4))

    // Em caso de erro
    if (vetor == NULL)
    {
        printf("Erro de alocação.");
        return 1;
    }

    for (i = 0; i<N; i++)
    {
        printf("Valor [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    menorValor = vetor[0];
    posicao = 0;

    for (i = 1; i<N; i++)
    {
        if (vetor[i] < menorValor)
        {
            menorValor = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menorValor);
    printf("Posição: %d\n", posicao);

    free(vetor);

    return 0;
}