#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Opera
{
    char url[100];
    char timeStamp[100];
} Opera;

typedef struct Stack
{
    Opera *arr;
    int top;
    int cap;
} Stack;

Stack *createStack(int n)
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->arr = (Opera *)malloc(n * sizeof(Opera));
    newStack->cap = n;
    newStack->top = -1;
    return newStack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == stack->cap - 1;
}

void push(Stack *stack, Opera opera)
{
    if (isFull(stack))
    {
        printf("Stack day\n");
        return;
    }
    stack->arr[++stack->top] = opera;
}

Opera pop(Stack *stack)
{
    Opera non = {"", ""};
    if (isEmpty(stack))
    {
        printf("Stack rong\n");
        return non;
    }
    return stack->arr[stack->top--];
}

Opera top(Stack *stack)
{
    Opera non = {"", ""};
    if (isEmpty(stack))
    {
        return non;
    }
    return stack->arr[stack->top];
}

void menu()
{
    printf("\n---------WEB HISTORY---------\n");
    printf("1. Truy cap URL moi\n");
    printf("2. Quay lai trang truoc\n");
    printf("3. Di toi trang sau\n");
    printf("4. Xem trang hien tai\n");
    printf("5. Thoat\n");
    printf("Chon chuc nang: ");
}

int main()
{
    int choice;
    char url[100], timeStamp[100];

    Stack *backward = createStack(100);
    Stack *forward = createStack(100);
    Opera current = {"", ""};

    do
    {
        menu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Nhap URL: ");
            fgets(url, sizeof(url), stdin);
            url[strcspn(url, "\n")] = 0;

            printf("Nhap thoi diem truy cap: ");
            fgets(timeStamp, sizeof(timeStamp), stdin);
            timeStamp[strcspn(timeStamp, "\n")] = 0;

            if (current.url[0] != '\0')
                push(backward, current);

            strcpy(current.url, url);
            strcpy(current.timeStamp, timeStamp);
            forward->top = -1;

            printf("Da truy cap: %s tai %s\n", current.url, current.timeStamp);
            break;

        case 2:
            if (isEmpty(backward))
            {
                printf("Khong co trang de quay lai\n");
            }
            else
            {
                push(forward, current);
                current = pop(backward);
                printf("Da quay lai: %s tai %s\n", current.url, current.timeStamp);
            }
            break;

        case 3:
            if (isEmpty(forward))
            {
                printf("Khong co trang de di toi\n");
            }
            else
            {
                push(backward, current);
                current = pop(forward);
                printf("Da di toi: %s tai %s\n", current.url, current.timeStamp);
            }
            break;

        case 4:
            if (current.url[0] == '\0')
                printf("Chua truy cap trang nao\n");
            else
                printf("Trang hien tai: %s tai %s\n", current.url, current.timeStamp);
            break;

        case 5:
            printf("Ket thuc chuong trinh\n");
            break;

        default:
            printf("Lua chon khong hop le\n");
        }

    } while (choice != 5);

    free(backward->arr);
    free(backward);
    free(forward->arr);
    free(forward);

    return 0;
}
