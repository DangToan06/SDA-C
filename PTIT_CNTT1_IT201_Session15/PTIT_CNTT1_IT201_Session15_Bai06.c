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

int deQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue khong ton tai");
        return -1;
    }
    return queue->arr[queue->front++];
}

int check(Queue *queue)
{
    if (queue->capacity <= 1)
    {
        return 1;
    }

    int temp = deQueue(queue);

    while (!isEmpty(queue))
    {
        int current = deQueue(queue);
        if (current != temp + 1)
        {
            return 0;
        }
        temp = current;
    }
    return 1;
}

void freeQueue(Queue *queue)
{
    free(queue->arr);
    free(queue);
}

int main()
{
    int n;
    scanf("%d", &n);
    Queue *queue = createQueue(n);

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        enQueue(queue, value);
    }

    if (check(queue))
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    return 0;
}