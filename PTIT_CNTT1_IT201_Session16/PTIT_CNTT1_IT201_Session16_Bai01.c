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

void init(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

int main()
{
    return 0;
}