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
        printf("cap phat dong khong thanh cong");
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

void getBetweenValue(Node *head)
{
    int size = getLength(head) / 2;
    Node *current = head;
    int flag;
    for (int i = 1; i <= size; i++)
    {
        current = current->next;
        flag = i;
    }
    printf("Node %d: %d", flag + 1, current->data);
}

int main()
{
    Node *head = creativeNode(5);
    Node *node1 = creativeNode(4);
    Node *node2 = creativeNode(3);
    Node *node3 = creativeNode(2);
    Node *node4 = creativeNode(1);
    Node *node5 = creativeNode(6);

    head->next = node1;
    node1->prev = head;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    getBetweenValue(head);
    return 0;
}