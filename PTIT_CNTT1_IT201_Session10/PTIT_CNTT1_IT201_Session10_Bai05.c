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

Node *removeHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *removeNode = head;
    head = head->next;
    free(removeNode);
    return head;
}

Node *deleteValue(Node *head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == value)
    {
        head = removeHead(head);
    }
    if (head == NULL)
    {
        return NULL;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        if (current->next->data == value)
        {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}

int main()
{
    Node *head = creativeNode(5);
    Node *node1 = creativeNode(4);
    Node *node2 = creativeNode(5);
    Node *node3 = creativeNode(2);
    Node *node4 = creativeNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    int value;
    scanf("%d", &value);
    printf("Node truoc khi xoa la:\n");
    printList(head);
    printf("Node sau khi xoa la:\n");
    head = deleteValue(head, value);
    printList(head);
    return 0;
}