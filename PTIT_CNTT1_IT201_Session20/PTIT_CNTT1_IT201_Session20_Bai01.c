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
        printf("Cap phat bo nhow khong thanh cong\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    printf("Nhap vao phan tu bat ky:\n");
    int n;
    scanf("%d", &n);

    Node *root = createNode(n);

    printf("%d", root->data);
    return 0;
}