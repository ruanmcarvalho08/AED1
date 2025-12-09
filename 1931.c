#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 2000000000 
#define MAX_C 10005     
#define MAX_HEAP 200005 

typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

Edge* adj[MAX_C];

typedef struct {
    int cost;
    int u;
    int parity; // 0 para par, 1 para ímpar
} State;

State minHeap[MAX_HEAP];
int heapSize = 0;

void add_edge(int u, int v, int w) {
    Edge* edge1 = (Edge*)malloc(sizeof(Edge));
    edge1->to = v;
    edge1->weight = w;
    edge1->next = adj[u];
    adj[u] = edge1;

    Edge* edge2 = (Edge*)malloc(sizeof(Edge));
    edge2->to = u;
    edge2->weight = w;
    edge2->next = adj[v];
    adj[v] = edge2;
}

void swap(State* a, State* b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (minHeap[idx].cost < minHeap[parent].cost) {
            swap(&minHeap[idx], &minHeap[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

void bubbleDown(int idx) {
    while (idx * 2 + 1 < heapSize) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int smallest = left;

        if (right < heapSize && minHeap[right].cost < minHeap[left].cost) {
            smallest = right;
        }

        if (minHeap[smallest].cost < minHeap[idx].cost) {
            swap(&minHeap[smallest], &minHeap[idx]);
            idx = smallest;
        } else {
            break;
        }
    }
}

void push(int cost, int u, int parity) {
    minHeap[heapSize].cost = cost;
    minHeap[heapSize].u = u;
    minHeap[heapSize].parity = parity;
    bubbleUp(heapSize);
    heapSize++;
}

State pop() {
    State top = minHeap[0];
    heapSize--;
    minHeap[0] = minHeap[heapSize];
    bubbleDown(0);
    return top;
}

int dist[MAX_C][2];

int main() {
    int C, V;
    
    if (scanf("%d %d", &C, &V) != EOF) {
        
        // Inicialização
        for (int i = 0; i <= C; i++) {
            adj[i] = NULL;
            dist[i][0] = INF;
            dist[i][1] = INF;
        }

        // Leitura do Grafo
        for (int i = 0; i < V; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
        }

        // Dijkstra
        dist[1][0] = 0;
        push(0, 1, 0);

        while (heapSize > 0) {
            State current = pop();
            int cost = current.cost;
            int u = current.u;
            int p = current.parity;

            if (cost > dist[u][p]) continue;

            Edge* temp = adj[u];
            while (temp != NULL) {
                int v = temp->to;
                int w = temp->weight;
                int new_parity = 1 - p; // Inverte a paridade (0->1, 1->0)
                int new_cost = cost + w;

                if (new_cost < dist[v][new_parity]) {
                    dist[v][new_parity] = new_cost;
                    push(new_cost, v, new_parity);
                }
                temp = temp->next;
            }
        }

        if (dist[C][0] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", dist[C][0]);
        }
        
       
        for(int i = 1; i <= C; i++) {
            Edge* curr = adj[i];
            while(curr != NULL) {
                Edge* aux = curr;
                curr = curr->next;
                free(aux);
            }
        }
    }

    return 0;
}