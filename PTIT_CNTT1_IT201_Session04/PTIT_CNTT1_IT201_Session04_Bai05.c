#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tmp(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

bool binarySearch(int *arr, int n, int target)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
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

    qsort(arr, n, sizeof(int), tmp);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int target;
    scanf("%d", &target);

    if (binarySearch(arr, n, target))
    {
        printf("\nPhan tu co trong mang");
    }
    else
    {
        printf("\nKhong tim thay phan tu");
    }

    free(arr);
    return 0;
}