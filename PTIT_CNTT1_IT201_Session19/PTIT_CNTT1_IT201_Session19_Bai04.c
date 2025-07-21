#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Cap phat bo nho khong thanh cong\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
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

    inorder(root);
    return 0;
}