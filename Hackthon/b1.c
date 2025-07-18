#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
    int id;
    char title[100];
    char author[100];
    char category[50];
    float privce;
} Book;

typedef struct Node
{
    Book data;
    struct Node *next;
} Node;

typedef struct Node2
{
    Book data;
    struct Node *next;
    struct Node *prev;
} Node2;

Node *createNode(Book book)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = book;
    newNode->next = NULL;
    return newNode;
}

void addListBook(Node *head, Book book)
{
}

int main()
{
    int choice;
    do
    {
        switch (choice)
        {
        case 1:
            /* code */
            break;

        default:
            break;
        }
    } while (choice);
    return 0;
}