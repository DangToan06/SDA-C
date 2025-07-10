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
    queue->arr = (int *)malloc(cap * sizeof(Queue));
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

int main()
{
    Queue *queue = createQueue(5);

    enQueue(queue, 6);

    if (isEmpty(queue))
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    return 0;
}