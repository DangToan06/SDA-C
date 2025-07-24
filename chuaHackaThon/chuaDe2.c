#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char action[50];
    char value;
} Operation;

typedef struct Node
{
    Operation *operation;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *initStack()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = NULL;
    return st;
}

int emptyStack(Stack *st)
{
    return st->top == NULL;
}

void pushStack(Stack *st, Operation *operation)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->operation = operation;
    newNode->next = st->top;
    st->top = newNode;
}

void popStack(Stack *st)
{
    if (emptyStack(st))
    {
        printf("Stack underflow!\n");
        return;
    }
    Node *tmp = st->top;
    st->top = tmp->next;

    free(tmp->operation);
    free(tmp);
}

Operation *topStack(Stack *st)
{
    if (emptyStack(st))
    {
        printf("Stack is empty!\n");
        return NULL;
    }
    return st->top->operation;
}

void freeStack(Stack *st)
{
    while (!emptyStack(st))
    {
        popStack(st);
    }
    free(st);
}

void menu()
{
    printf("1. Insert x\n");
    printf("2. Undo\n");
    printf("3. Redo\n");
    printf("4. Display\n");
    printf("0. Exit\n");
}

int main()
{
    Stack *undo = initStack();
    Stack *redo = initStack();
    char s[100];
    int idx = 0;
    int choice;
    do
    {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        getchar();

        if (choice == 1)
        {
            if (idx >= 100)
            {
                printf("String is full, cannot insert more characters.\n");
                continue;
            }
            char c;
            printf("Enter character to insert: ");
            scanf("%c", &c);
            getchar();

            Operation *op = (Operation *)malloc(sizeof(Operation));
            op->value = c;
            snprintf(op->action, sizeof(op->action), "Insert '%c'", c);
            pushStack(undo, op);
            s[idx++] = c;
        }
        else if (choice == 2)
        {
            if (emptyStack(undo))
            {
                printf("Nothing to undo.\n");
            }
            else
            {
                Operation *op = topStack(undo);
                printf("Undo char: %c\n", op->value);
                idx--;
                popStack(undo);
                pushStack(redo, op);
            }
        }
        else if (choice == 3)
        {
            if (emptyStack(redo))
            {
                printf("Nothing to redo.\n");
            }
            else
            {
                Operation *op = topStack(redo);
                printf("Redo char: %c\n", op->value);
                s[idx++] = op->value;
                popStack(redo);
                pushStack(undo, op);
            }
        }
        else if (choice == 4)
        {
            printf("Current string: ");
            for (int i = 0; i < idx; i++)
            {
                printf("%c", s[i]);
            }
            printf("\n");
        }

        else if (choice == 0)
        {
            printf("Exiting the programming.\n");
            freeStack(undo);
            freeStack(redo);
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}
