#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int findLevel(Node *root, int target)
{
    if (root == NULL)
        return 0;

    typedef struct
    {
        Node *node;
        int level;
    } QueueNode;

    QueueNode queue[100];
    int front = 0, rear = 0;

    queue[rear++] = (QueueNode){root, 1};

    while (front < rear)
    {
        QueueNode current = queue[front++];
        if (current.node->data == target)
        {
            return current.level;
        }

        if (current.node->left != NULL)
            queue[rear++] = (QueueNode){current.node->left, current.level + 1};

        if (current.node->right != NULL)
            queue[rear++] = (QueueNode){current.node->right, current.level + 1};
    }

    return 0;
}

int main()
{
    Node *root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    int target;
    printf("Nhap gia tri can tim level: ");
    scanf("%d", &target);

    int level = findLevel(root, target);
    if (level)
        printf("Nut co gia tri %d o tang %d\n", target, level);
    else
        printf("Khong tim thay nut co gia tri %d trong cay\n", target);

    return 0;
}