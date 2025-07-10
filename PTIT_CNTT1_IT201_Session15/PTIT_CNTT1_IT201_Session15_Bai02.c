#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int font;
    int rear;
    int capacity;
} Queue;

Queue *createQueue(int cap)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(cap * sizeof(int));
    queue->font = 0;
    queue->rear = -1;
    queue->capacity = cap;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->rear < queue->font;
}

int isFull(Queue *queue)
{
    return queue->rear == queue->capacity - 1;
}

void enQueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }

    queue->arr[++queue->rear] = value;
}

void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue isn't exist");
        return;
    }

    for (int i = queue->font; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
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
    enQueue(queue, 4);

    int value;
    scanf("%d", &value);
    enQueue(queue, value);

    displayQueue(queue);
    freeQueue(queue);
    return 0;
}