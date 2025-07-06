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

Node *removeHead(Node *head)
{
    Node *removeNode = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(removeNode);
    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

Node *removeAt(Node *head, int pos)
{
    if (pos == 1)
    {
        return removeHead(head);
    }
    if (pos == getLength(head))
    {
        return removeTail(head);
    }

    if (pos > getLength(head) || pos <= 0)
    {
        return head;
    }

    Node *current = head;
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }

    Node *temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
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

    int pos;
    printf("Nhap vi tri can xoa:\n");
    scanf("%d", &pos);
    printf("Node list luc dau la\n");
    printNode(head);

    printf("Ndoe list sau khi xoa la\n");
    head = removeAt(head, pos);
    printNode(head);
    return 0;
}