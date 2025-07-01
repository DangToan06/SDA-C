#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int start, int end, int value)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == value)
    {
        return mid + 1;
    }
    else if (value < arr[mid])
    {
        return binarySearch(arr, start, mid - 1, value);
    }
    else if (arr[mid] < value)
    {
        return binarySearch(arr, mid + 1, end, value);
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

    int value;
    scanf("%d", &value);

    if (binarySearch(arr, 0, n - 1, value) == -1)
    {
        printf("Khong tim thay\n");
    }
    else
    {
        printf("Phan tu o vi tri %d\n", binarySearch(arr, 0, n - 1, value));
    }

    free(arr);
    return 0;
}

// Truong hop tot nhat O(1)
// Truong hop trung binh O(log n)
// Truong hop  xau nhat O(log n)