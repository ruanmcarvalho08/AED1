#include <stdio.h>

int main() {
    // definindo as variáveis
    int n, m, id, i;
    int fila[50005];
    int saiu[100005] = {0}; 

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &id);
        saiu[id] = 1; // marca quem saiu
    }

    int primeiro = 1;

    for (i = 0; i < n; i++) {
        // se saiu[id] for 0 (falso), imprime. se for 1 (verdadeiro), pula.
        if (!saiu[fila[i]]) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");

    return 0;
}