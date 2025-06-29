#include <stdio.h>
#include <stdlib.h>

void findMinMax(int arr[], int i, int n, int *min, int *max)
{
    if (i == n)
    {
        return;
    }

    if (arr[i] > *max)
    {
        *max = arr[i];
    }

    if (arr[i] < *min)
    {
        *min = arr[i];
    }

    findMinMax(arr, i + 1, n, min, max);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];

    findMinMax(arr, 1, n, &min, &max);

    printf("%d -- %d", min, max);
    return 0;
}