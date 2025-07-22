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
    if (!newNode)
        return NULL;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct Queue
{
    Node **arr;
    int front, rear, capacity;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Node **)malloc(capacity * sizeof(Node *));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    return q;
}

int isEmpty(Queue *q)
{
    return q->rear < q->front;
}

void enQueue(Queue *q, Node *node)
{
    if (q->rear < q->capacity - 1)
        q->arr[++q->rear] = node;
}

Node *deQueue(Queue *q)
{
    if (!isEmpty(q))
        return q->arr[q->front++];
    return NULL;
}

void preOrder(Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void deleteNode(Node *root, int key)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
        {
            free(root);
            root = NULL;
        }
        return;
    }

    Queue *queue = createQueue(100);
    enQueue(queue, root);

    Node *target = NULL;
    Node *last = NULL;
    Node *parentOfLast = NULL;

    while (!isEmpty(queue))
    {
        Node *temp = deQueue(queue);

        if (temp->data == key)
        {
            target = temp;
        }

        if (temp->left)
        {
            parentOfLast = temp;
            last = temp->left;
            enQueue(queue, temp->left);
        }

        if (temp->right)
        {
            parentOfLast = temp;
            last = temp->right;
            enQueue(queue, temp->right);
        }
    }

    if (target && last)
    {
        target->data = last->data;

        if (parentOfLast->right == last)
        {
            parentOfLast->right = NULL;
        }
        else if (parentOfLast->left == last)
        {
            parentOfLast->left = NULL;
        }
        free(last);
    }

    free(queue->arr);
    free(queue);
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

    int deleteValue;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &deleteValue);
    deleteNode(root, deleteValue);

    printf("Cay sau khi xoa %d: ", deleteValue);
    preOrder(root);
    printf("\n");

    return 0;
}
