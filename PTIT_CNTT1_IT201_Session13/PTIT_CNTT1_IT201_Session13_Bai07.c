#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct Stack
{
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
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
    if (stack->top == MAX - 1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Stack da day");
        exit(1);
    }

    stack->data[++stack->top] = value;
}

void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack khong ton tai");
        exit(1);
    }

    stack->data[stack->top--];
}

char top(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack rong, khong co phan tu tren cung!\n");
        exit(1);
    }
    return stack->data[stack->top];
}

bool check(char string[])
{
    Stack stack;
    initStack(&stack);
    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (string[i] == '{' || string[i] == '[' || string[i] == '(')
        {
            push(&stack, string[i]);
        }
        else if (!isEmpty(&stack) && string[i] == '}' && top(&stack) == '{')
        {
            pop(&stack);
        }
        else if (!isEmpty(&stack) && string[i] == ']' && top(&stack) == '[')
        {
            pop(&stack);
        }
        else if (!isEmpty(&stack) && string[i] == ')' && top(&stack) == '(')
        {
            pop(&stack);
        }
    }
    if (!isEmpty(&stack))
    {
        return false;
    }
    return true;
}

int main()
{
    char str[MAX];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (check(str) == true)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    return 0;
}