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
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printNode(Node *head)
{
    Node *current = head;
    int count = 1;
    while (current != NULL)
    {
        printf("Node %d: %d\n", count++, current->data);
        current = current->next;
    }
}

int main()
{
    Node *head = creativeNode(1);
    Node *note1 = creativeNode(2);
    Node *note2 = creativeNode(3);
    Node *note3 = creativeNode(4);
    Node *note4 = creativeNode(5);

    head->next = note1;
    note1->next = note2;
    note2->next = note3;
    note3->next = note4;
    note4->next = NULL;
    printNode(head);
    return 0;
}