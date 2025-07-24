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

    graph->arr = (int **)calloc(vertex, sizeof(int *));
    for (int i = 0; i < vertex; i++)
    {
        graph->arr[i] = (int *)calloc(vertex, sizeof(int));
    }

    return graph;
}

void addEdge(Graph *graph, int firstNode, int secondNode)
{
    if (firstNode >= 0 && firstNode < graph->vertex &&
        secondNode >= 0 && secondNode < graph->vertex)
    {
        graph->arr[firstNode][secondNode] = 1;
        graph->arr[secondNode][firstNode] = 1;
    }
    else
    {
        printf("Gia tri khong hop le\n");
    }
}

// Đếm số cạnh nối với một đỉnh
void count(Graph *graph, int value)
{
    int count = 0;
    for (int i = 0; i < graph->vertex; i++)
    {
        if (graph->arr[value][i] == 1)
        {
            count++;
        }
    }
    printf("So canh noi voi dinh %d: %d\n", value, count);
}

int main()
{
    int vertex, t;
    scanf("%d %d", &vertex, &t);

    Graph *graph = createGraph(vertex);

    int firstNode, secondNode;
    while (t--)
    {
        scanf("%d %d", &firstNode, &secondNode);
        addEdge(graph, firstNode, secondNode);
    }

    int value;
    scanf("%d", &value);

    count(graph, value);

    return 0;
}
