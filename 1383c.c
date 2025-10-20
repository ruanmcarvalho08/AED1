//Alocação dinâmica
#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int verificaSudoku(int **matriz);

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){

        //Alocação dinâmica da matriz
        int **matriz = (int **) malloc(SIZE * sizeof(int *));
        if(matriz == NULL) return 0;

        for (int i = 0; i < SIZE; i++){
            matriz[i] = (int *) malloc(SIZE * sizeof(int));
            if(matriz[i] == NULL) return 0;
        }

        for (int linha = 0; linha < SIZE; linha++){
            for (int coluna = 0; coluna < SIZE; coluna++){
                scanf("%d", &matriz[linha][coluna]);
            }
        }

        printf("Instancia %d\n", i);
        if(!verificaSudoku(matriz)){
            printf("NAO\n\n");
        } else
            printf("SIM\n\n");

        // Liberação de memória

        for (int i = 0; i < SIZE; i++){
            free(matriz[i]);
        }
        free(matriz);

    }
}

int verificaSequencia(int *valores){
    int numeros[SIZE + 1] = {0}; //SIZE + 1 para ler até o valor de índice 9.

    for (int i = 0; i < SIZE; i++){
        int valor = valores[i];
        if(valor < 1 || valor > 9 || numeros[valor] != 0){
            return 0;
        }
        numeros[valor] = 1; //1 para já apareceu esse número anteriormente.
    }

    return 1;
}

int verificaLinha(int **matriz){
    int *valores = (int *) malloc(SIZE * sizeof(int)); //Alocação dinâmica para o vetor valores.

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            valores[j] = matriz[i][j];
        }

        if (!verificaSequencia(valores)){
            free(valores); //Liberação da memória
            return 0;
        }
    }

    free(valores); //Liberação da memória
    return 1;
}

int verificaColuna(int **matriz){
    int *valores = (int *) malloc(SIZE * sizeof(int)); //Alocação dinâmica para o vetor valores.

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            valores[j] = matriz[j][i];
        }

        if (!verificaSequencia(valores)){
            free(valores); //Liberação da memória
            return 0;
        }
    }

    free(valores); //Liberação da memória
    return 1;
}

int verificaSubMatriz(int **matriz){
    int *valores = (int *) malloc(SIZE * sizeof(int));

    for(int bi = 0; bi < SIZE; bi+=3){
        for(int bj = 0; bj < SIZE; bj+=3){
            int k = 0;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    valores[k] = matriz[bi + i][bj + j];
                    k++;
                }
            }

            if(!verificaSequencia(valores)){
                free(valores);
                return 0;
            }
        }
    }

    free(valores);
    return 1;
}

int verificaSudoku(int **matriz){
    return verificaColuna(matriz) && verificaLinha(matriz) && verificaSubMatriz(matriz);
}