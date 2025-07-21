#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        printf("Cap phat bo nho khong thah cong\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool searchBinaryTree(Node *root, int valueSearch)
{
    if (root != NULL)
    {
        if (valueSearch == root->data)
        {
            return true;
        }
        return searchBinaryTree(root->left, valueSearch) || searchBinaryTree(root->right, valueSearch);
    }
    return false;
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

    int valueSearch;
    scanf("%d", &valueSearch);

    if (searchBinaryTree(root, valueSearch))
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    return 0;
}