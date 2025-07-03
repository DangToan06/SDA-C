#include <stdio.h>
#include <stdlib.h>

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
        printf("Cap phat bo nho that bai");
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

    printf("NULL\n");
}

int getLegnth(Node *head)
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

void getMiddle(Node *head, int n)
{
    Node *current = head;
    for (int i = 0; i < n; i++)
    {
        current = current->next;
    }
    printf("%d", current->data);
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
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    if (getLegnth(head) % 2 != 0)
    {
        int n = (getLegnth(head) / 2);
        getMiddle(head, n);
    }
    else
    {
        int n = (getLegnth(head) / 2);
        getMiddle(head, n);
    }
    return 0;
}