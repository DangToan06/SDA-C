#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

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
    else if (arr[mid] > value)
    {
        return binarySearch(arr, start, mid - 1, value);
    }
    else
    {
        return binarySearch(arr, mid + 1, end, value);
    }
}

int linearSearch(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Mang sau khi duoc xap xep la:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    int value;
    printf("\nNhap vao Phan tu muon tim kiem:\n");
    scanf("%d", &value);

    if (binarySearch(arr, 0, n - 1, value) == -1)
    {
        printf("Khong tim thay\n");
    }
    else
    {
        printf("Tim kiem nhi pha: %d\n", binarySearch(arr, 0, n - 1, value));
    }

    if (linearSearch(arr, n, value) == -1)
    {
        printf("Khong tim thay phan tu\n");
    }
    else
    {
        printf("Tim kiem tuyen tinh: %d\n", linearSearch(arr, n, value));
    }
    free(arr);
    return 0;
}