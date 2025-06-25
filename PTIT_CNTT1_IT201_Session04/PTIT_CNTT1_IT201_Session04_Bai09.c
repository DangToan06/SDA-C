#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tmp(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

int binarySearch(int *arr, int start, int end, int target)
{
    if (start > end)
    {
        return 0;
    }
    int mid = (start + end) / 2;

    if (arr[mid] == target)
    {
        return 1;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, end, target);
    }
    else
    {
        return binarySearch(arr, start, mid - 1, target);
    }
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

    if (binarySearch(arr, 0, n - 1, target))
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