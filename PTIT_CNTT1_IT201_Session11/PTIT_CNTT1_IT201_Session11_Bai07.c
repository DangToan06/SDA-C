#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
    newNode->prev = NULL;
    return newNode;
}

int getLength(Node *head)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

Node *insertHead(Node *head, int value)
{
    Node *newNode = creativeNode(value);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

Node *insertTail(Node *head, int value)
{
    Node *current = head;
    Node *newNode = creativeNode(value);
    if (head == NULL)
    {
        return newNode;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node *insertAt(Node *head, int value, int pos)
{
    Node *newNode = creativeNode(value);
    if (pos == 1)
    {
        return insertHead(head, value);
    }
    if (pos == getLength(head))
    {
        return insertTail(head, value);
    }

    if (pos > getLength(head) || pos <= 0)
    {
        return head;
    }

    Node *current = head;
    for (int i = 0; i < pos - 2; i++)
    {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    current->next->prev = newNode;
    current->next = newNode;
    return head;
}

void printNode(Node *head)
{
    printf("NULL <-> ");
    Node *current = head;
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = creativeNode(1);
    Node *node1 = creativeNode(2);
    Node *node2 = creativeNode(3);
    Node *node3 = creativeNode(4);
    Node *node4 = creativeNode(5);

    head->next = node1;
    node1->prev = head;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;

    int value, pos;
    printf("Nhap gia tri can chen:\n");
    scanf("%d", &value);
    printf("Nhap vi tri can chen:\n");
    scanf("%d", &pos);
    printf("Node list luc dau la\n");
    printNode(head);

    printf("Ndoe list sau khi chen la\n");
    head = insertAt(head, value, pos);
    printNode(head);
    return 0;
}