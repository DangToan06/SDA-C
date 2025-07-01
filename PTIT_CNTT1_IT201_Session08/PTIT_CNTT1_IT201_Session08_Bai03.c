#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int check = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                check = 1;
            }
        }
        if (!check)
        {
            break;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("so luong phan tu khong hop le");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

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