#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf(" %d", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d", root->val);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d", root->val);
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
    int c, n, val, i, caseNum = 1;

    scanf("%d", &c);

    while (c--) {
        scanf("%d", &n);
        Node* root = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &val);
            root = insert(root, val);
        }

        printf("Case %d:\n", caseNum++);
        
        printf("Pre.:");
        preOrder(root);
        printf("\n");

        printf("In..:");
        inOrder(root);
        printf("\n");

        printf("Post:");
        postOrder(root);
        printf("\n\n");

        freeTree(root);
    }

    return 0;
}