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

void addEdge(Node *graph[], int vertex, int arr[][vertex])
{
    for (int i = 0; i < vertex; i++)
    {
        graph[i] = NULL;
        for (int j = 0; j < vertex; j++)
        {
            if (arr[i][j] == 1)
            {
                Node *newNode = createNode(j);
                if (graph[i] == NULL)
                {
                    graph[i] = newNode;
                }
                else
                {
                    Node *current = graph[i];
                    while (current->next != NULL)
                    {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
        }
    }
}

void printNode(Node *graph[], int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        printf("%d: ", i);
        Node *current = graph[i];
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeNode(Node *graph[], int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        Node *current = graph[i];
        while (current != NULL)
        {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }
}

int main()
{
    int vertex;
    scanf("%d", &vertex);

    int arr[vertex][vertex];

    Node *graph[vertex];
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    addEdge(graph, vertex, arr);

    printNode(graph, vertex);

    freeNode(graph, vertex);

    return 0;
}