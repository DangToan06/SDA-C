#include <stdio.h>

void search(int *arr, int n)
{
    int max = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            printf("%d ", arr[i]);
            max = arr[i];
        }
    }
    printf("%d", arr[n - 1]);
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

    search(arr, n);

    free(arr);
    return 0;
}