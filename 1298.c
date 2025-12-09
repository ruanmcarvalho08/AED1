#include <stdio.h>
#include <stdlib.h>

#define MAXN 305
#define MAX_NODES (2 * MAXN + 5) * (2 * MAXN + 5)

typedef struct {
    int u, v;   
    int w;          
    int id;     
} Edge;

int parent[MAX_NODES];
int used_barrier[MAXN * MAXN * 2]; 
Edge edges[MAXN * MAXN * 4];

int get_id(int r, int c, int width) {
    return r * width + c;
}

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

int join(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
        return 1;
    }
    return 0;
}

int cmp(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->w - e2->w;
}

int main() {
    int N;

    while (scanf("%d", &N) != EOF) {
        int rows = 2 * N;
        int cols = 2 * N + 1;
        int width = cols + 1; 

        int total_nodes = (rows + 1) * (cols + 1);
        for (int i = 0; i <= total_nodes; i++) parent[i] = i;
        
        int super_root = total_nodes; 
        parent[super_root] = super_root;
   
        for (int r = 0; r <= rows; r++) {
            for (int c = 0; c <= cols; c++) {
                if ((r + c) % 2 != 0) {
                    if (r == 0 || r == rows || c == 0 || c == cols) {
                        join(get_id(r, c, width), super_root);
                    }
                }
            }
        }

        int edge_count = 0;
        int barrier_count = 0;
        char buffer[MAXN + 5];

        for (int r = 1; r < rows; r++) {
            scanf("%s", buffer);
            for (int j = 1; j <= N; j++) {
                int c;
                if (r % 2 != 0) c = 2 * j - 1; // Linha ímpar
                else c = 2 * j;                // Linha par

                int u_v = get_id(r - 1, c, width);
                int v_v = get_id(r + 1, c, width);
                
                int u_h = get_id(r, c - 1, width);
                int v_h = get_id(r, c + 1, width);

                barrier_count++;
                used_barrier[barrier_count] = 0;

                char type = buffer[j - 1];
                
                if (type == 'V') {
                    edges[edge_count++] = (Edge){u_v, v_v, 0, barrier_count};
                    edges[edge_count++] = (Edge){u_h, v_h, 1, barrier_count};
                } 
                else {
                    edges[edge_count++] = (Edge){u_h, v_h, 0, barrier_count};
                    edges[edge_count++] = (Edge){u_v, v_v, 1, barrier_count};
                }
            }
        }

        qsort(edges, edge_count, sizeof(Edge), cmp);

        int swaps = 0;
        for (int i = 0; i < edge_count; i++) {
            int b_id = edges[i].id;
            
            if (used_barrier[b_id]) continue;

            if (join(edges[i].u, edges[i].v)) {
                swaps += edges[i].w;
                used_barrier[b_id] = 1;
            }
        }

        printf("%d\n", swaps);
    }
    return 0;
}