#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[flag])
            {
                flag = j;
            }
        }
        swap(&arr[i], &arr[flag]);
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

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

// Truong hop tot nhat O(n^2)
// Truong hop trung binh O(n^2)
// Truong hop  xau nhat O(n^2)