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
        printf("Cap phat khong thanh cong\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct
{
    Node *data[100];
    int front, rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = 0;
}

int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, Node *x)
{
    q->data[q->rear++] = x;
}

Node *dequeue(Queue *q)
{
    return q->data[q->front++];
}

void levelOrderTraversal(Node *root, int value)
{
    if (root == NULL)
        return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q))
    {
        Node *curr = dequeue(&q);
        if (curr->data == value)
        {
            printf("TRUE\n");
            exit(0);
        }

        if (curr->left != NULL)
            enqueue(&q, curr->left);
        if (curr->right != NULL)
            enqueue(&q, curr->right);
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

    int valueSearch;
    scanf("%d", &valueSearch);

    levelOrderTraversal(root, valueSearch);

    printf("FALSE\n");
    return 0;
}