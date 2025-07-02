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
        printf("Cap phat bo nho khong thanh cong");
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

int lengthNode(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
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

Node *removeTail(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *currnet = head;
    while (currnet->next->next != NULL)
    {
        currnet = currnet->next;
    }
    Node *removeNode = currnet->next;
    currnet->next = NULL;
    free(removeNode);
    return head;
}

Node *removeAt(Node *head, int index)
{
    if (index < 0 || index > lengthNode(head))
    {
        printf("Vi tri ban them khong thoa man");
        exit(1);
    }

    if (index == 0)
    {
        return removeHead(head);
    }
    if (index == lengthNode(head) - 1)
    {
        return removeTail(head);
    }

    Node *current = head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }

    Node *removeNode = current->next;
    Node *next = removeNode->next;

    current->next = next;

    free(removeNode);
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

    int index;
    printf("Nhap vi tri muon xoa:\n");
    scanf("%d", &index);

    printf("Truocw khi xoa:\n");
    printNode(head);

    removeAt(head, index);
    printf("sau khi xoa:\n");
    printNode(head);
    return 0;
}
