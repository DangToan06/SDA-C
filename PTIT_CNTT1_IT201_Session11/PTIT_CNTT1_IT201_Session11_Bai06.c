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

Node *removeHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
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

    printf("Node list luc dau la\n");
    printNode(head);

    printf("Ndoe list sau khi xoa la\n");
    head = removeHead(head);
    printNode(head);
    return 0;
}