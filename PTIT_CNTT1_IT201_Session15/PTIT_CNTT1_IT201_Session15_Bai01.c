#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int font;
    int rear;
    int capacity;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(capacity * sizeof(int));
    queue->font = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->font > queue->rear;
}

int isFull(Queue *queue)
{
    return queue->rear == queue->capacity - 1;
}

void enQueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue da day");
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
    return queue->arr[queue->font++];
}

int getFont(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue khong ton tai");
        return -1;
    }
    return queue->arr[queue->font];
}

void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue khong ton tai");
        return;
    }
    for (int i = queue->font; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
}

void freeQueue(Queue *queue)
{
    free(queue->arr);
    free(queue);
}

int main()
{
    Queue *queue = createQueue(1);

    return 0;
}