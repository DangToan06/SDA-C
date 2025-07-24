#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node *graph[], int u, int v)
{
    Node *newNodeV = createNode(v);
    newNodeV->next = graph[u];
    graph[u] = newNodeV;

    Node *newNodeU = createNode(u);
    newNodeU->next = graph[v];
    graph[v] = newNodeU;
}

void printGraph(Node *graph[], int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        Node *temp = graph[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Node *graph[], int vertex)
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
    int vertex = 3;
    Node *graph[vertex];

    for (int i = 0; i < vertex; i++)
    {
        graph[i] = NULL;
    }

    addEdge(graph, 0, 1);

    printGraph(graph, vertex);

    freeGraph(graph, vertex);
    return 0;
}
