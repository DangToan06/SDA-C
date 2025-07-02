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

Node *insertHead(Node *head, int value)
{
    Node *newNode = creativeNode(value);
    newNode->next = head;
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

int lengthNode(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

Node *insertAt(Node *head, int value, int index)
{
    if (index < 0 || index > lengthNode(head))
    {
        printf("Vi tri ban them khong thoa man");
        exit(1);
    }

    if (index == 0)
    {
        return insertHead(head, value);
    }
    if (index == lengthNode(head))
    {
        return insertTail(head, value);
    }

    Node *current = head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }

    Node *newNode = creativeNode(value);

    Node *nextNode = current->next;
    current->next = newNode;
    newNode->next = nextNode;
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

    int index,
        value;
    printf("Nhap gia tri muon them:\n");
    scanf("%d", &value);
    printf("Nhap vi tri muon them:\n");
    scanf("%d", &index);

    printf("Truocw khi Them:\n");
    printNode(head);

    head = insertAt(head, value, index);
    printf("sau khi them:\n");
    printNode(head);
    return 0;
}
