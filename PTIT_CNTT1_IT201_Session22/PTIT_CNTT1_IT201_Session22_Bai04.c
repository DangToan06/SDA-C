#include <stdio.h>

int main()
{
    int vertex, count = 0, firstNode, secondNode;
    scanf("%d", &vertex);

    int arr[vertex][vertex];

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = i + 1; j < vertex; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }
    }

    printf("%d", count);
    return 0;
}