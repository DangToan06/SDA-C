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

typedef struct Queue
{
    Node **arr;
    int front, rear, capacity;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (Node **)malloc(capacity * sizeof(Node *));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->rear < queue->front;
}

int isFull(Queue *queue)
{
    return queue->rear == queue->capacity - 1;
}

void enQueue(Queue *queue, Node *node)
{
    if (isFull(queue))
        return;
    queue->arr[++queue->rear] = node;
}

Node *deQueue(Queue *queue)
{
    if (isEmpty(queue))
        return NULL;
    return queue->arr[queue->front++];
}

Node *insert(Node *root, int data)
{
    Node *newNode = createNode(data);
    if (root == NULL)
        return newNode;

    Queue *queue = createQueue(100);
    enQueue(queue, root);

    while (!isEmpty(queue))
    {
        Node *node = deQueue(queue);

        if (node->left != NULL)
        {
            enQueue(queue, node->left);
        }
        else
        {
            node->left = newNode;
            free(queue->arr);
            free(queue);
            return root;
        }

        if (node->right != NULL)
        {
            enQueue(queue, node->right);
        }
        else
        {
            node->right = newNode;
            free(queue->arr);
            free(queue);
            return root;
        }
    }

    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
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

    int value;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);

    root = insert(root, value);

    printf("Cay sau khi them: ");
    preorder(root);
    printf("\n");

    return 0;
}
