#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char c) {
    if (root == NULL) return createNode(c);
    if (c < root->data) 
        root->left = insert(root->left, c);
    else 
        root->right = insert(root->right, c);
    return root;
}

int search(Node* root, char c) {
    if (root == NULL) return 0;
    if (root->data == c) return 1;
    if (c < root->data) 
        return search(root->left, c);
    else 
        return search(root->right, c);
}

void infix(Node* root, int* first) {
    if (root != NULL) {
        infix(root->left, first);
        if (!*first) printf(" ");
        printf("%c", root->data);
        *first = 0;
        infix(root->right, first);
    }
}

void prefix(Node* root, int* first) {
    if (root != NULL) {
        if (!*first) printf(" ");
        printf("%c", root->data);
        *first = 0;
        prefix(root->left, first);
        prefix(root->right, first);
    }
}

void postfix(Node* root, int* first) {
    if (root != NULL) {
        postfix(root->left, first);
        postfix(root->right, first);
        if (!*first) printf(" ");
        printf("%c", root->data);
        *first = 0;
    }
}

int main() {
    Node* root = NULL;
    char command[20];
    char val;
    int first;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "I") == 0) {
            scanf(" %c", &val);
            root = insert(root, val);
        } else if (strcmp(command, "P") == 0) {
            scanf(" %c", &val);
            if (search(root, val)) {
                printf("%c existe\n", val);
            } else {
                printf("%c nao existe\n", val);
            }
        } else {
            first = 1;
            if (strcmp(command, "INFIXA") == 0) {
                infix(root, &first);
            } else if (strcmp(command, "PREFIXA") == 0) {
                prefix(root, &first);
            } else if (strcmp(command, "POSFIXA") == 0) {
                postfix(root, &first);
            }
            printf("\n");
        }
    }

    return 0;
}