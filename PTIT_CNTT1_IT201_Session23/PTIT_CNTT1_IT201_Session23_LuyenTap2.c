#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Request
{
    int id;
    char issue[30];
    int priority;
} Request;

typedef struct Queue
{
    Request *arr;
    int front;
    int rear;
    int capacity;
} Queue;

Queue *createQueue(int cap)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (Request *)malloc(cap * sizeof(Request));
    queue->capacity = cap;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->front > queue->rear;
}

int isFull(Queue *queue)
{
    return queue->rear == queue->capacity - 1;
}

void enQueue(Queue *queue, Request request)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }

    queue->arr[++queue->rear] = request;
}

Request deQueue(Queue *queue)
{
    Request emptyRequest = {-1, "", -1};
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return emptyRequest;
    }

    return queue->arr[queue->front++];
}

Request top(Queue *queue)
{
    Request emptyRequest = {-1, "", -1};
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return emptyRequest;
    }

    return queue->arr[queue->front];
}

void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("No requests in this queue.\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("ID: %d | Issue: %s | Priority: %d\n",
               queue->arr[i].id,
               queue->arr[i].issue,
               queue->arr[i].priority);
    }
}

void menu()
{
    system("cls");
    printf("----------REQUEST SYSTEM----------\n");
    printf("1. REQUEST (Send request)\n");
    printf("2. HANDLE REQUEST (Process request)\n");
    printf("3. TOP REQUEST (View top request)\n");
    printf("4. DISPLAY all requests\n");
    printf("5. EXIT\n");
    printf("Enter your choice: ");
}

int main()
{
    Queue *highQueue = createQueue(100);
    Queue *lowQueue = createQueue(100);
    int choice;
    int idCounter = 1;

    do
    {
        menu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
        {
            Request req;
            req.id = idCounter++;
            printf("Enter issue description: ");
            fgets(req.issue, sizeof(req.issue), stdin);
            req.issue[strcspn(req.issue, "\n")] = '\0';

            do
            {
                printf("Enter priority (1 = HIGH, 2 = LOW): ");
                scanf("%d", &req.priority);
            } while (req.priority != 1 && req.priority != 2);

            if (req.priority == 1)
                enQueue(highQueue, req);
            else
                enQueue(lowQueue, req);

            printf("Request submitted successfully!\n");
            getchar();
            getchar();
            break;
        }

        case 2:
        {
            Request handled;
            if (!isEmpty(highQueue))
                handled = deQueue(highQueue);
            else if (!isEmpty(lowQueue))
                handled = deQueue(lowQueue);
            else
            {
                printf("No requests to handle.\n");
                getchar();
                getchar();
                break;
            }

            printf("Handled Request ID: %d | Issue: %s | Priority: %d\n",
                   handled.id, handled.issue, handled.priority);
            getchar();
            getchar();
            break;
        }

        case 3:
        {
            Request topReq;
            if (!isEmpty(highQueue))
                topReq = top(highQueue);
            else if (!isEmpty(lowQueue))
                topReq = top(lowQueue);
            else
            {
                printf("No pending requests.\n");
                getchar();
                getchar();
                break;
            }

            printf("Top Request ID: %d | Issue: %s | Priority: %d\n",
                   topReq.id, topReq.issue, topReq.priority);
            getchar();
            getchar();
            break;
        }

        case 4:
        {
            printf("--- High Priority Queue ---\n");
            displayQueue(highQueue);
            printf("--- Low Priority Queue ---\n");
            displayQueue(lowQueue);
            getchar();
            getchar();
            break;
        }

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
            getchar();
            getchar();
        }

    } while (choice != 5);

    free(highQueue->arr);
    free(lowQueue->arr);
    free(highQueue);
    free(lowQueue);

    return 0;
}
