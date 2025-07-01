#include <stdio.h>
#include <stdlib.h>

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
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int value;

    scanf("%d", &value);

    if (linearSearch(arr, n, value) == -1)
    {
        printf("Khong tim thay phan tu\n");
    }
    else
    {
        printf("Vi tri %d\n", linearSearch(arr, n, value));
    }

    free(arr);
    return 0;
}

// Truong hop tot nhat O(1)
// Truong hop trung binh O(n)
// Truong hop  xau nhat O(n)