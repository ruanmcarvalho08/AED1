#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** table, int M, int value) {
    int index = value % M;
    Node* newNode = createNode(value);
    
    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printTable(Node** table, int M) {
    for (int i = 0; i < M; i++) {
        printf("%d -> ", i);
        Node* current = table[i];
        while (current != NULL) {
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("\\\n");
    }
}

void freeTable(Node** table, int M) {
    for (int i = 0; i < M; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int caseNum = 0; caseNum < N; caseNum++) {
        int M, C;
        scanf("%d %d", &M, &C);
        
        Node** table = (Node**)calloc(M, sizeof(Node*));
        
        for (int i = 0; i < C; i++) {
            int value;
            scanf("%d", &value);
            insert(table, M, value);
        }
        
        printTable(table, M);
        
        if (caseNum < N - 1) {
            printf("\n");
        }
        
        freeTable(table, M);
        free(table);
    }
    
    return 0;
}