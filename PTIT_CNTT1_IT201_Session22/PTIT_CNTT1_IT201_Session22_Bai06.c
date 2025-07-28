#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int vertex;
    int **arr;
} Graph;

Graph *createGrap(int vertex)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertex = vertex;
    graph->arr = (int **)calloc(vertex, sizeof(int *));
    for (int i = 0; i < vertex; i++)
    {
        graph->arr[i] = (int *)calloc(vertex, sizeof(int));
    }
    return graph;
}