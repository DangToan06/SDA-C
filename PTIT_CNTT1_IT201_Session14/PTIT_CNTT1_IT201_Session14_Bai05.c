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
        printf("Cap phat bo nho khong thanh cong");
        return 0;
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
    return stack->head == NULL;
}

void push(Stack *stack, int value)
{
    Node *newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Danh sach lien ket khong ton tai");
        exit(1);
    }

    Node *temp = stack->head;
    int value = temp->data;
    stack->head = temp->next;
    free(temp);
    return value;
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

    printf("%d", pop(stack));
    freeStack(stack);
    return 0;
}