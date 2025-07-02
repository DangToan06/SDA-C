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
        printf("Bo nhow khong duoc cap phat");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *insertTail(Node *head, int value)
{
    Node *newNode = creativeNode(value);
    if (head == NULL)
    {
        return newNode;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
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

Node *removeHead(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main()
{
    Node *head = NULL;

    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        head = insertTail(head, temp);
    }

    printf("Danh sach lien ket luc dau:\n");
    printNode(head);
    head = removeHead(head);
    printf("\nDanh sach lien ket sau khi bi xoa:\n");
    printNode(head);
    return 0;
}