#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *head;
} Stack;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Cap phat bo nho thanh cong");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

int isEmpty(Stack *stack)
{
    if (stack->head == NULL)
    {
        return 1;
    }
    return 0;
}

void push(Stack *stack, int value)
{
    Node *newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}

void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack rong");
        exit(1);
    }

    Node *temp = stack->head;
    int value = temp->data;
    stack->head = temp->next;
    free(temp);
}

void displayStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack rong");
        return;
    }

    Node *current = stack->head;

    while (current != NULL)
    {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeStack(Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}

int main()
{
    Stack *stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    int value;
    scanf("%d", &value);

    printf("Stack truoc khi them:\n");
    displayStack(stack);

    push(stack, value);

    printf("Stack sau khi them:\n");
    displayStack(stack);
    freeStack(stack);

    return 0;
}
