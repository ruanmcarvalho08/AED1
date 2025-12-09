#include <stdio.h>
#include <limits.h>

#define MAX 250

int grafo[MAX][MAX];
int dist[MAX];
int visitado[MAX];

int dijkstra(int n, int origem, int destino, int c) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visitado[i] = 0;
    }
    dist[origem] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visitado[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1 || dist[u] == INT_MAX) break;
        visitado[u] = 1;

        for (int v = 0; v < n; v++) {
            if (grafo[u][v] != -1 && !visitado[v]) {
                int novo_dist = dist[u] + grafo[u][v];
                if (novo_dist < dist[v]) {
                    dist[v] = novo_dist;
                }
            }
        }
    }

    return dist[destino] == INT_MAX ? -1 : dist[destino];
}

int main() {
    int n, m, c, k;
    while (scanf("%d %d %d %d", &n, &m, &c, &k), n != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grafo[i][j] = -1;
            }
        }

        for (int i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            if (u >= c && v >= c) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
            if (u >= c && v < c) {
                grafo[u][v] = p;
            }
            if (u < c && v >= c) {
                grafo[v][u] = p;
            }
            if (u < c && v < c && abs(u - v) == 1) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        int resultado = dijkstra(n, k, c - 1, c);
        printf("%d\n", resultado);
    }
    return 0;
}