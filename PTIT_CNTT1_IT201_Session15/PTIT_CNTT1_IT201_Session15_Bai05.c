#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

Queue *createQueue(int cap)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(cap * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = cap;
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

void enQueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full");
        return;
    }
    queue->arr[++queue->rear] = value;
}

int getFront(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty");
        return -1;
    }

    return queue->arr[queue->front];
}

void freeQueue(Queue *queue)
{
    free(queue->arr);
    free(queue);
}

int main()
{
    Queue *queue = createQueue(5);

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);

    printf("%d", getFront(queue));

    freeQueue(queue);
    return 0;
}