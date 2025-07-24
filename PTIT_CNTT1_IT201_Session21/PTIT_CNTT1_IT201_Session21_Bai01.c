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
    for (int i = 0; i < graph->vertex; i++)
    {
        graph->arr[i] = (int *)malloc(vertex * sizeof(int));
        for (int j = 0; j < vertex; j++)
        {
            graph->arr[i][j] = 0;
        }
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
        printf("Chi so khong hop le\n");
    }
}

void printGraph(Graph *graph)
{
    printf("Ma tran ke cua do thi:\n");
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

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);

    printGraph(graph);

    freeGraph(graph);
    return 0;
}