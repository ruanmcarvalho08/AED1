#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

int main(){
    int n;

    while(scanf("%d", &n) != EOF){

        int pilha[MAX], top = -1; // top(indíce do topo) = -1 significa que a pilha não existe.
        int fila[MAX], front = 0, rear = 0; // front: índice do início da fila; rear: índice do final da fila.
        int fp[MAX], fp_size = 0; // fp: fila de prioridade; fp_size: quantidade de elementos.
        bool ehPilha = true, ehFila = true, ehFP = true;

        for (int i = 0; i < n; i++){
            int op, x;

            scanf("%d %d", &op, &x);

            if (op == 1){ //Adição
                if (ehPilha) pilha[++top] = x;
                if (ehFila) fila[rear++] = x;
                if (ehFP) fp[fp_size++] = x;
            } else{ //Remoção e verificação
                //Pilha
                if (ehPilha){
                if (top == -1 || pilha[top--] != x)
                    ehPilha = false;
                }

                //Fila
                if (ehFila){
                    if (front == rear || fila[front++] != x)
                        ehFila = false;
                }

                //Fila de Prioridade
                if (ehFP){
                    if (fp_size == 0) ehFP = false;
                    else{
                        // Verifica o maior valor
                        int maxIndex = 0;
                        for(int j = 1; j < fp_size; j++){
                            if (fp[j] > fp[maxIndex]) maxIndex = j;
                        }
                        if(fp[maxIndex] != x) ehFP = false;

                        fp[maxIndex] = fp[--fp_size];
                    }
                }
            }
        }

        int count = ehFila + ehFP + ehPilha;
        if(count == 0) 
            printf("impossible\n");
        else if(count > 1) 
            printf("not sure\n");
        else if(ehFila) 
            printf("queue\n");
        else if(ehPilha) 
            printf("stack\n");
        else 
            printf("priority queue\n");
    }
    return 0;
}

