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

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}

int main()
{
    Node *head = creativeNode(5);
    Node *node1 = creativeNode(4);
    Node *node2 = creativeNode(3);
    Node *node3 = creativeNode(2);
    Node *node4 = creativeNode(1);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    printList(head);
    return 0;
}