#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct {
    Node** data;
    int front, rear, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (Node**)malloc(capacity * sizeof(Node*));
    q->front = q->rear = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, Node* node) {
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % q->capacity;
}

Node* dequeue(Queue* q) {
    Node* node = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return node;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void levelOrder(Node* root, int n) {
    if (root == NULL) return;
    
    Queue* q = createQueue(n);
    enqueue(q, root);
    
    printf("%d", root->value);
    
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        
        if (current->left != NULL) {
            printf(" %d", current->left->value);
            enqueue(q, current->left);
        }
        if (current->right != NULL) {
            printf(" %d", current->right->value);
            enqueue(q, current->right);
        }
    }
    printf("\n");
    
    free(q->data);
    free(q);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int C, N;
    scanf("%d", &C);
    
    for (int caseNum = 1; caseNum <= C; caseNum++) {
        scanf("%d", &N);
        Node* root = NULL;
        
        for (int i = 0; i < N; i++) {
            int value;
            scanf("%d", &value);
            root = insert(root, value);
        }
        
        printf("Case %d:\n", caseNum);
        levelOrder(root, N);
        printf("\n");
        
        freeTree(root);
    }
    
    return 0;
}