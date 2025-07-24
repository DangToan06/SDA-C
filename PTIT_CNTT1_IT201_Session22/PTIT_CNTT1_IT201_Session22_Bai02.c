#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node *graph[], int firstNode, int secondNode)
{
    Node *newNodeF = createNode(firstNode);

    if (graph[secondNode] == NULL)
    {
        graph[secondNode] = newNodeF;
    }
    else
    {
        Node *current = graph[secondNode];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNodeF;
    }

    Node *newNodeS = createNode(secondNode);

    if (graph[firstNode] == NULL)
    {
        graph[firstNode] = newNodeS;
    }
    else
    {
        Node *temp = graph[firstNode];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNodeS;
    }
}

void printNode(Node *graph[], int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        printf("%d: ", i);
        Node *temp = graph[i];
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeNode(Node *graph[], int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        Node *temp = graph[i];
        while (temp != NULL)
        {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
}

int main()
{
    int vertex;
    scanf("%d", &vertex);

    Node *graph[vertex];

    for (int i = 0; i < vertex; i++)
    {
        graph[i] = NULL;
    }

    int firstNode, secondNode;

    while (scanf("%d %d", &firstNode, &secondNode) == 2)
    {
        addEdge(graph, firstNode, secondNode);
    }
    printNode(graph, vertex);
    return 0;
}