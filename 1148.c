#include <stdio.h>
#include <limits.h>

#define INF 1000000000
#define MAX 501

int g[MAX][MAX];
int dist[MAX], visited[MAX];

int main(){
    int n, e;
    while(scanf("%d %d", &n, &e) && (n || e)){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = INF;

        for(int i = 0; i < e; i++){
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);

            if(g[y][x] != INF)
                g[x][y] = g[y][x] = 0;
            else
                g[x][y] = h;
        }

        int k;
        scanf("%d", &k);

        while(k--){
            int o, d;
            scanf("%d %d", &o, &d);

            for(int i=1;i<=n;i++){
                dist[i] = INF;
                visited[i] = 0;
            }

            dist[o] = 0;

            for(int i = 1; i <= n; i++){
                int u = -1;

                for(int j = 1; j <= n; j++)
                    if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                        u = j;

                visited[u] = 1;

                for(int v = 1; v <= n; v++){
                    if(dist[u] + g[u][v] < dist[v])
                        dist[v] = dist[u] + g[u][v];
                }
            }

            if(dist[d] == INF) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", dist[d]);
        }
        printf("\n");
    }
    return 0;
}