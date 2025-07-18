#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Phone
{
    char phoneNumber[10];
    char timeCall[10];
} Phone;

typedef struct Node
{
    Phone data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

typedef struct Stack
{
    Node *top;
} Stack;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Node *createNode(char phoneNumber[], char timeCall[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data.phoneNumber, phoneNumber);
    strcpy(newNode->data.timeCall, timeCall);
    newNode->next = NULL;
    return newNode;
}

int isEmptyStack(Stack *stack)
{
    return stack->top == NULL;
}

int isEmptyQueue(Queue *queue)
{
    return queue->front == NULL;
}

void push(Stack *stack, char phoneNumber[], char timeCall[])
{
    Node *newNode = createNode(phoneNumber, timeCall);
    newNode->next = stack->top;
    stack->top = newNode;
}

void enQueue(Queue *queue, char phoneNumber[], char timeCall[])
{
    Node *newNode = createNode(phoneNumber, timeCall);
    if (isEmptyQueue(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Node *pop(Stack *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack is empty\n");
        return NULL;
    }

    Node *temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

void display(Queue *queue)
{
    if (isEmptyQueue(queue))
    {
        printf("Not have queue\n");
        return;
    }

    Node *current = queue->front;
    while (current != NULL)
    {
        printf("%s || %s\n", current->data.phoneNumber, current->data.timeCall);
        current = current->next;
    }
}

char *getTime()
{
    static char buffer[10];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
    return buffer;
}

void menu()
{
    system("cls");
    printf("----------Call History Manager----------\n");
    printf("1. Call\n");
    printf("2. Back\n");
    printf("3. Redial\n");
    printf("4. History\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    Queue *callHistoryQueue = createQueue();
    Stack *callBackStack = createStack();
    Stack *callForwardStack = createStack();
    char phoneNumber[10], timeCall[10];
    do
    {
        menu();
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            system("cls");
            printf("Enter phone number\n");
            fgets(phoneNumber, sizeof(phoneNumber), stdin);
            phoneNumber[strcspn(phoneNumber, "\n")] = '\0';
            strcpy(timeCall, getTime());
            push(callBackStack, phoneNumber, timeCall);
            enQueue(callHistoryQueue, phoneNumber, timeCall);
            printf("Call new number success\n");
            getchar();
            break;
        case 2:
            system("cls");
            Node *value = pop(callBackStack);
            push(callForwardStack, value->data.phoneNumber, value->data.timeCall);
            printf("Call success\n");
            getchar();
            break;
        case 3:
            system("cls");
            if (isEmptyStack(callForwardStack))
            {
                printf("No have call\n");
            }
            else
            {
                Node *value = pop(callForwardStack);
                push(callBackStack, value->data.phoneNumber, value->data.timeCall);
                enQueue(callHistoryQueue, value->data.phoneNumber, value->data.timeCall);
                printf("Call back success\n");
            }
            getchar();
            break;
        case 4:
            system("cls");
            display(callHistoryQueue);
            getchar();
            break;
        default:
            system("cls");
            printf("Error\n");
            getchar();
            break;
        }
    } while (choice != 5);
    return 0;
}
