#include <stdio.h>
#include <stdlib.h>

typedef struct { short x, y; } P;
P *queue;

char **grid;

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) == 2) {

        // aloca a grade dinamicamente
        grid = (char **) malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            grid[i] = (char *) malloc((m + 1) * sizeof(char));
            scanf("%s", grid[i]);
        }

        // fila com tamanho exato (não desperdiça memória)
        queue = (P *) malloc(n * m * sizeof(P));

        int components = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '.') {
                    components++;

                    int ini = 0, fim = 0;
                    queue[fim++] = (P){i, j};
                    grid[i][j] = '#';

                    while (ini < fim) {
                        P p = queue[ini++];
                        int x = p.x, y = p.y;

                        if (x+1 < n && grid[x+1][y] == '.') {
                            grid[x+1][y] = '#';
                            queue[fim++] = (P){x+1, y};
                        }
                        if (x-1 >= 0 && grid[x-1][y] == '.') {
                            grid[x-1][y] = '#';
                            queue[fim++] = (P){x-1, y};
                        }
                        if (y+1 < m && grid[x][y+1] == '.') {
                            grid[x][y+1] = '#';
                            queue[fim++] = (P){x, y+1};
                        }
                        if (y-1 >= 0 && grid[x][y-1] == '.') {
                            grid[x][y-1] = '#';
                            queue[fim++] = (P){x, y-1};
                        }
                    }
                }
            }
        }

        printf("%d\n", components);

        // libera tudo
        for (int i = 0; i < n; i++)
            free(grid[i]);
        free(grid);
        free(queue);
    }

    return 0;
}