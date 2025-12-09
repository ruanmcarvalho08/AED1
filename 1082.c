#include <stdio.h>

int g[30][30], vis[30];
int n;

void dfs_collect(int u, int comp[], int *len) {
    vis[u] = 1;
    comp[(*len)++] = u;
    for (int v = 0; v < n; v++)
        if (g[u][v] && !vis[v])
            dfs_collect(v, comp, len);
}

int main() {
    int t, e, caso = 1;
    if (scanf("%d", &t)!=1) return 0;
    while (t--) {
        scanf("%d %d", &n, &e);
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
            for (int j = 0; j < n; j++) g[i][j] = 0;
        }
        while (e--) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int x = a - 'a', y = b - 'a';
            g[x][y] = g[y][x] = 1;
        }

        printf("Case #%d:\n", caso++);
        int comps = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int comp[30], len = 0;
                dfs_collect(i, comp, &len);
                // sort component (simple selection sort; n<=26)
                for (int p = 0; p < len-1; p++) {
                    int min = p;
                    for (int q = p+1; q < len; q++)
                        if (comp[q] < comp[min]) min = q;
                    if (min != p) {
                        int tmp = comp[p]; comp[p] = comp[min]; comp[min] = tmp;
                    }
                }
                for (int k = 0; k < len; k++)
                    printf("%c,", 'a' + comp[k]);
                printf("\n");
                comps++;
            }
        }
        printf("%d connected components\n\n", comps);
    }
    return 0;
}