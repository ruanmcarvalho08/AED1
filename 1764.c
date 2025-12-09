#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int compare(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    
    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int kruskal(Edge edges[], int M, int N) {
    int* parent = (int*)malloc(N * sizeof(int));
    int* rank = (int*)calloc(N, sizeof(int));
    int mstWeight = 0;
    int edgesUsed = 0;
    
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    
    qsort(edges, M, sizeof(Edge), compare);
    
    for (int i = 0; i < M && edgesUsed < N - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        
        int setU = find(parent, u);
        int setV = find(parent, v);
        
        if (setU != setV) {
            mstWeight += edges[i].weight;
            unionSets(parent, rank, setU, setV);
            edgesUsed++;
        }
    }
    
    free(parent);
    free(rank);
    
    return mstWeight;
}

int main() {
    int N, M;
    
    while (scanf("%d %d", &N, &M), N || M) {
        Edge* edges = (Edge*)malloc(M * sizeof(Edge));
        
        for (int i = 0; i < M; i++) {
            int X, Y, Z;
            scanf("%d %d %d", &X, &Y, &Z);
            edges[i].u = X;
            edges[i].v = Y;
            edges[i].weight = Z;
        }
        
        int totalWeight = kruskal(edges, M, N);
        printf("%d\n", totalWeight);
        
        free(edges);
    }
    
    return 0;
}