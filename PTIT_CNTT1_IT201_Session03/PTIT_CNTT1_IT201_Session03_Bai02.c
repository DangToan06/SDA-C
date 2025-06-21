#include <stdio.h>
#include <stdlib.h>

int findMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        return printf("So luong phan tu khong hop le");
    }
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, n);

    printf("max = %d", max);
    free(arr);
    return 0;
}