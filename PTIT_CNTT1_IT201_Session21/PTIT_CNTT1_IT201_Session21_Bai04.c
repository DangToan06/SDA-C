#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int vertex;
    int **arr;
} Graph;

Graph *createGraph(int vertex)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertex = vertex;
    graph->arr = (int **)malloc(vertex * sizeof(int *));

    for (int i = 0; i < vertex; i++)
    {
        graph->arr[i] = (int *)malloc(vertex * sizeof(int));
        for (int j = 0; j < vertex; j++)
        {
            graph->arr[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph *graph, int startNode, int endNode)
{
    if (startNode >= 0 && startNode < graph->vertex && endNode >= 0 && endNode < graph->vertex)
    {
        graph->arr[startNode][endNode] = 1;
    }
    else
    {
        printf("Vi tri khong thoa man\n");
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
    int vertex = 3;
    Graph *graph = createGraph(vertex);

    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    printGraph(graph);

    freeGraph(graph);
    return 0;
}