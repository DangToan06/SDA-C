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
    newNode->prev = current;

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
    node4->prev = node3;

    int value;
    scanf("%d", &value);
    printf("Danh sach lien ket truoc khi them la:\n");
    printNode(head);

    head = insertTail(head, value);
    printf("Danh sach lien ket sau khi them la:\n");
    printNode(head);
    return 0;
}
