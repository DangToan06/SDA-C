#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 30
#define MAX 100

typedef struct Customer
{
    char name[MAXNAME];
    int old;
} Customer;

typedef struct Queue
{
    Customer arr[MAX];
    int front;
    int rear;
    int count;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->count == 0;
}

int isFull(Queue *queue)
{
    return queue->count == MAX;
}

void enQueue(Queue *queue, char *name, int old)
{
    system("cls");
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX;
    strncpy(queue->arr[queue->rear].name, name, MAXNAME - 1);
    queue->arr[queue->rear].name[MAXNAME - 1] = '\0';
    queue->arr[queue->rear].old = old;
    queue->count++;
    printf("Add success!\n");
    getchar();
    getchar();
}

void deQueue(Queue *queue)
{
    system("cls");
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Serving customers name: %s age: %d\n", queue->arr[queue->front].name, queue->arr[queue->front].old);
    queue->front = (queue->front + 1) % MAX;
    queue->count--;
    getchar();
}

void displayQueue(Queue *queueNormal, Queue *queueOld)
{
    system("cls");
    if (isEmpty(queueNormal) && isEmpty(queueOld))
    {
        printf("Queue is empty\n");
        return;
    }

    if (!isEmpty(queueNormal))
    {
        printf("Danh sach nguoi duoi 60 la:\n");
        for (int i = 0; i < queueNormal->count; i++)
        {
            int index = (queueNormal->front + i) % MAX;
            printf("%d. Ten: %s Tuoi: %d\n", i + 1, queueNormal->arr[index].name, queueNormal->arr[index].old);
        }
    }
    if (!isEmpty(queueOld))
    {
        printf("Danh sach nguoi tren 60 la:\n");
        for (int i = 0; i < queueOld->count; i++)
        {
            int index = (queueOld->front + i) % MAX;
            printf("%d. Ten: %s Tuoi: %d\n", i + 1, queueOld->arr[index].name, queueOld->arr[index].old);
        }
    }
    getchar();
}

void menu()
{
    system("cls");
    printf("----------Bank Manager---------\n");
    printf("1. Add customer to queue\n");
    printf("2. Serving customers\n");
    printf("3. List customer\n");
    printf("4. Exits\n");
    printf("Your choice: ");
}

int main()
{
    Queue *queueNormal = createQueue();
    Queue *queueOld = createQueue();

    int choice;
    char name[MAXNAME];
    int old;
    do
    {
        menu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Enter name customer\n");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter Old:\n");
            scanf("%d", &old);

            if (old >= 60)
            {
                enQueue(queueOld, name, old);
            }
            else
            {
                enQueue(queueNormal, name, old);
            }
            break;
        case 2:
            if (isEmpty(queueOld))
            {
                deQueue(queueNormal);
            }
            else
            {
                deQueue(queueOld);
            }
            break;
        case 3:
            displayQueue(queueNormal, queueOld);
            break;
        case 4:
            printf("Exit manager");
            break;
        default:
            printf("Intput error");
            break;
        }
    } while (choice != 4);
    free(queueNormal);
    free(queueOld);
    return 0;
}