#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

Node *creativeNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Cap phat bo nho khong thanh cong");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Stack *creativeStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int main()
{
    Stack *stack = creativeStack();

    if (stack->top == NULL)
    {
        printf("Khoi tao stack thanh cong");
    }
    else
    {
        printf("KHong the khoi tao stack");
    }

    free(stack);
    return 0;
}
