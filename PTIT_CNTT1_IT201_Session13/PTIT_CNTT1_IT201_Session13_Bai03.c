#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *data;
    int top;
    int max;
} Stack;

Stack creativeStack(int maxSize)
{
    Stack stack;
    stack.data = (int *)malloc(maxSize * sizeof(int));
    stack.top = -1;
    stack.max = maxSize;
    return stack;
}

int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *stack)
{
    if (stack->top == stack->max - 1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("stack da day");
        return;
    }

    stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("No element in stack");
        exit(1);
    }

    int temp = stack->data[stack->top--];
    return temp;
}

int main()
{
    Stack stack = creativeStack(5);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    int temp = pop(&stack);
    printf("%d", temp);
    return 0;
}