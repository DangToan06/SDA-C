#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 30
#define MAX 100

typedef struct Customer
{
    char name[MAXNAME];

} Customer;

typedef struct Queue
{
    Customer arr[MAX];
    int font;
    int rear;
    int count;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->font = 0;
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

void enQueue(Queue *queue, char *name)
{
    system("cls");
    if (isFull(queue))
    {
        printf("Queue is full");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    strncpy(queue->arr[queue->rear].name, name, MAXNAME - 1);
    queue->arr[queue->rear].name[MAXNAME - 1] = '\0';
    queue->count++;
    printf("Add success!");
    getchar();
}

void deQueue(Queue *queue)
{
    system("cls");
    if (isEmpty(queue))
    {
        printf("Queue is empty");
        return;
    }

    printf("Serving customers %s", queue->arr[queue->font].name);
    queue->font = (queue->font + 1) % MAX;
    queue->count--;
    printf("\nRemove success!");
    getchar();
}

void displayQueue(Queue *queue)
{
    system("cls");
    if (isEmpty(queue))
    {
        printf("Queue is empty");
        return;
    }

    printf("List customer:\n");
    for (int i = 0; i < queue->count; i++)
    {
        int index = (queue->font + i) % MAX;
        printf("%d. %s\n", i + 1, queue->arr[index].name);
    }
    getchar();
}

void menu()
{
    system("cls");
    printf("----------Ticket Manager---------\n");
    printf("1. Add customer to queue\n");
    printf("2. Serving customers\n");
    printf("3. List customer\n");
    printf("4. Exits\n");
    printf("Your choice: ");
}

int main()
{
    Queue *queue = createQueue();

    int choice;
    char name[MAXNAME];
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
            enQueue(queue, name);
            break;
        case 2:
            deQueue(queue);
            break;
        case 3:
            displayQueue(queue);
            break;
        case 4:
            printf("Exit manager");
            break;
        default:
            printf("Intput error");
            break;
        }
    } while (choice != 4);

    free(queue);
    return 0;
}