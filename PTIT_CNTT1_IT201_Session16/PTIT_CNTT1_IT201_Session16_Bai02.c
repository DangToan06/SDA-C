#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->front == NULL;
}

void enQueue(Queue *queue, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Ds khong ton tai");
        return;
    }

    Node *current = queue->front;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeQueue(Queue *queue)
{
    Node *current = queue->front;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(queue);
}

int main()
{
    Queue *queue = createQueue();

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);

    int value;
    scanf("%d", &value);

    printf("Truoc khi them:\n");
    displayQueue(queue);

    enQueue(queue, value);
    printf("Sau khi them:\n");
    displayQueue(queue);

    freeQueue(queue);
    return 0;
}