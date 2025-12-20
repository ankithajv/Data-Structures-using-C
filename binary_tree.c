#include <stdio.h>
#include <stdlib.h> 

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* makeTree() {
    Node *newNode;
    int info;
    printf("Enter the info or -1 for null\n");
    scanf("%d", &info);

    if (info == -1) {
        return NULL;
    }

    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = info;

    printf("Enter the left child of %d\n", info);
    newNode->left = makeTree();
    
    printf("Enter the right child of %d\n", info);
    newNode->right = makeTree();

    return newNode;
}

void printPreorder(Node *treeNode) {
    if (treeNode != NULL) {
        printf("%d -> ", treeNode->data);
        printPreorder(treeNode->left);
        printPreorder(treeNode->right);
    }
}

void printPostorder(Node *treeNode) {
    if (treeNode != NULL) {
        printPostorder(treeNode->left);
        printPostorder(treeNode->right);
        printf("%d -> ", treeNode->data);
    }
}

void printInorder(Node *treeNode) {
    if (treeNode != NULL) {
        printInorder(treeNode->left);
        printf("%d -> ", treeNode->data);
        printInorder(treeNode->right);
    }
}

int main() {
    Node *root;
    root = makeTree();

    printf("\nPreorder: ");
    printPreorder(root);

    printf("\nPostorder: ");
    printPostorder(root);

    printf("\nInorder: ");
    printInorder(root);
    
    printf("\n");

    return 0;
}