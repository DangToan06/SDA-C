#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int vertex;
    int **arr;
} Graph;

Graph *createGraph(int v)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertex = v;
    graph->arr = (int **)calloc(v, sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        graph->arr[i] = (int *)calloc(v, sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph, int firstNode, int secondNode)
{
    if (firstNode >= 0 && firstNode < graph->vertex && secondNode >= 0 && secondNode < graph->vertex)
    {
        graph->arr[firstNode][secondNode] = 1;
        graph->arr[secondNode][firstNode] = 1;
    }
    else
    {
        printf("Gia tri khong hop le\n");
    }
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->vertex; i++)
    {
        for (int j = 0; j < graph->vertex; j++)
        {
            printf("%d ", graph->arr[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->vertex; i++)
    {
        free(graph->arr[i]);
    }
    free(graph->arr);
    free(graph);
}

int main()
{
    int vertex;
    scanf("%d", &vertex);

    Graph *graph = createGraph(vertex);

    int firstNode, secondNode;

    while (scanf("%d %d", &firstNode, &secondNode) == 2)
    {
        addEdge(graph, firstNode, secondNode);
    }
    printGraph(graph);
    return 0;
}