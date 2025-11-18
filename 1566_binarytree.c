#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int altura;
    int count;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int h) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->altura = h;
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int h) {
    if (root == NULL) {
        return createNode(h);
    }
    if (h == root->altura) {
        root->count++;
    } else if (h < root->altura) {
        root->left = insert(root->left, h);
    } else {
        root->right = insert(root->right, h);
    }
    return root;
}

void inOrder(Node* root, int *first) {
    if (root != NULL) {
        inOrder(root->left, first);
        for (int i = 0; i < root->count; i++) {
            if (!*first) printf(" ");
            printf("%d", root->altura);
            *first = 0;
        }
        inOrder(root->right, first);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int nc, n, h, i;

    scanf("%d", &nc);

    while (nc--) {
        scanf("%d", &n);
        Node* root = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &h);
            root = insert(root, h);
        }

        int first = 1;
        inOrder(root, &first);
        printf("\n");

        freeTree(root);
    }

    return 0;
}