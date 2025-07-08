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
        printf("Stack da day\n");
        return;
    }

    stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    int value = stack->data[stack->top--];
    return value;
}

void freeStack(Stack *stack)
{
    free(stack->data);
}

void displayStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack khong ton tai\n");
        return;
    }
    for (int i = 0; i < stack->max; i++)
    {
        printf("%d\n", pop(stack));
    }

    freeStack(stack);
}

int main()
{
    Stack stack = creativeStack(5);
    printf("Nhap cac phan tu\n");
    for (int i = 0; i < 7; i++)
    {
        int value;
        scanf("%d", &value);
        push(&stack, value);
    }

    displayStack(&stack);
    return 0;
}
