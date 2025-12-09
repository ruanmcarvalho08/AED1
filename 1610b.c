#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dest;
    struct node* next;
} Node;

typedef struct {
    Node** adjList;
    int* visited;
    int N;
} Graph;

Graph* createGraph(int N) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->N = N;
    graph->adjList = (Node**)malloc(N * sizeof(Node*));
    graph->visited = (int*)calloc(N, sizeof(int));
    
    for (int i = 0; i < N; i++) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

int dfs(Graph* graph, int node) {
    graph->visited[node] = 1;
    
    Node* current = graph->adjList[node];
    while (current != NULL) {
        if (graph->visited[current->dest] == 1) {
            return 1;
        } else if (graph->visited[current->dest] == 0) {
            if (dfs(graph, current->dest)) {
                return 1;
            }
        }
        current = current->next;
    }
    
    graph->visited[node] = 2;
    return 0;
}

int hasCycle(Graph* graph) {
    for (int i = 0; i < graph->N; i++) {
        graph->visited[i] = 0;
    }
    
    for (int i = 0; i < graph->N; i++) {
        if (graph->visited[i] == 0) {
            if (dfs(graph, i)) {
                return 1;
            }
        }
    }
    
    return 0;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->N; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph->visited);
    free(graph);
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        Graph* graph = createGraph(N);
        
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            addEdge(graph, A-1, B-1);
        }
        
        if (hasCycle(graph)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        freeGraph(graph);
    }
    
    return 0;
}