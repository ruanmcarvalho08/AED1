#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int m;
        scanf("%d", &m);

        int notas[1005];
        int ordenado[1005];

        for (int i = 0; i < m; i++) {
            scanf("%d", &notas[i]);
            ordenado[i] = notas[i];
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - i - 1; j++) {
                if (ordenado[j] < ordenado[j + 1]) {
                    int temp = ordenado[j];
                    ordenado[j] = ordenado[j + 1];
                    ordenado[j + 1] = temp;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            if (notas[i] == ordenado[i]) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}