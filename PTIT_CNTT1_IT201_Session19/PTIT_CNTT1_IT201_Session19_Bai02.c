#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Node khoi tao khong thanh cong");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);

    root = node1;
    root->left = node2;
    root->right = node3;
    root->left->left = node4;

    preorder(root);
    return 0;
}