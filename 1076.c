#include <stdio.h>
int vis[200];
int g[200][200];
int cnt, n;

void dfs(int u){
    vis[u] = 1;
    for(int v=0; v<n; v++)
        if (g[u][v] && !vis[v]) {
            cnt++;
            dfs(v);
        }
}

int main(){
    int t, a, b, soma;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &soma);
        scanf("%d %d", &n, &a);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) g[i][j]=0;
            vis[i]=0;
        }
        for(int i=0;i<a;i++){
            scanf("%d %d", &b, &soma);
            g[b][soma] = g[soma][b] = 1;
        }
        cnt = 0;
        dfs(soma);
        printf("%d\n", cnt*2);
    }
    return 0;
}