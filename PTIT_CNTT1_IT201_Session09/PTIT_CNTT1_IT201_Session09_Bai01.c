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
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = creativeNode(10);
    Node *note1 = creativeNode(20);
    Node *note2 = creativeNode(30);
    Node *note3 = creativeNode(40);
    Node *note4 = creativeNode(50);

    head->next = note1;
    note1->next = note2;
    note2->next = note3;
    note3->next = note4;
    note4->next = NULL;

    printNode(head);
    return 0;
}