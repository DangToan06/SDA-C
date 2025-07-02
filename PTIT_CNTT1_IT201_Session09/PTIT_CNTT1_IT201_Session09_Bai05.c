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
        printf("Khong the cap phat bo nho");
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

Node *insertHead(Node *head, int value)
{
    Node *newNode = creativeNode(value);
    newNode->next = head;
    return newNode;
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

    int value;
    printf("Nhap gia tri muon them vao dau: \n");
    scanf("%d", &value);
    head = insertHead(head, value);

    printNode(head);
    return 0;
}