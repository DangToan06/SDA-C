#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool searchValue(Node *head, int value)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
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

    int value;
    scanf("%d", &value);

    if (searchValue(head, value))
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    return 0;
}