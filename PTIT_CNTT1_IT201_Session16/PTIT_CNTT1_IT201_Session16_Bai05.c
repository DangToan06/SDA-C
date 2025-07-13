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
    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void deQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Ds rong");
        return;
    }

    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
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

    printf("Truoc khi xoa:\n");
    displayQueue(queue);

    deQueue(queue);

    printf("Sau khi xoa:\n");
    displayQueue(queue);

    freeQueue(queue);
}