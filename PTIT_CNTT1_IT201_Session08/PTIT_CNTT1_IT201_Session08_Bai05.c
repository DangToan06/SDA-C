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

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

// Truong hop tot nhat O(n)
// Truong hop trung binh O(n^2)
// Truong hop  xau nhat O(n^2)