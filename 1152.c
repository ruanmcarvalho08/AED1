#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int u, v, w;
} Edge;

int parent[200000];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;
}

int cmp(const void *a, const void *b){
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main(){
    int m, n;
    while(scanf("%d %d", &m, &n), m){
        Edge edges[n];
        int total = 0;

        for(int i=0;i<m;i++) parent[i] = i;

        for(int i=0;i<n;i++){
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            total += edges[i].w;
        }

        qsort(edges, n, sizeof(Edge), cmp);

        int mst = 0;

        for(int i=0;i<n;i++){
            if(find(edges[i].u) != find(edges[i].v)){
                mst += edges[i].w;
                unite(edges[i].u, edges[i].v);
            }
        }

        printf("%d\n", total - mst);
    }
    return 0;
}
