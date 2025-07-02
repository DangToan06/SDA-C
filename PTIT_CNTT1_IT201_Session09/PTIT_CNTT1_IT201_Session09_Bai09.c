#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *creativeNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Cap phat bo nho khong thanh cong");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *insertTail(Node *head, int value)
{
    Node *newNode = creativeNode(value);
    if (head == NULL)
    {
        return newNode;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printNode(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    Node *head = NULL;

    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        head = insertTail(head, temp);
    }

    printf("Truoc khi dao nguoc:\n");
    printNode(head);
    head = reverseList(head);
    printf("Sau khi dao nguoc:\n");
    printNode(head);
    return 0;
}
