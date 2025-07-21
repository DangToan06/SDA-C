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
        printf("Cap phat bo nho khong thanh cong\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    int value;
    printf("Nhap vao gia tri ban muon khoi tao:\n");
    createNode(scanf("%d", &value));

    return 0;
}