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
        printf("Stack da day");
        exit(1);
    }

    stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack khong ton tai");
        exit(1);
    }

    int temp = stack->data[stack->top--];
    return temp;
}

void freeStack(Stack *stack)
{
    free(stack->data);
}

void revestArray(int arr[], int n)
{
    Stack stack = creativeStack(n);

    for (int i = 0; i < n; i++)
    {
        push(&stack, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = pop(&stack);
    }
    freeStack(&stack);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi dao nguoc la:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    revestArray(arr, n);
    printf("Mang sau khi dao nguoc la:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}