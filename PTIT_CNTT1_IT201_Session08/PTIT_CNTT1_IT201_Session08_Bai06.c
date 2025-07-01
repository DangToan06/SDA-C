#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[left++] = L[i++];
        }
        else
        {
            arr[left++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[left++] = L[i++];
    }

    while (j < n2)
    {
        arr[left++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

// Truong hop tot nhat O(n log n)
// Truong hop trung binh O(n log n)
// Truong hop  xau nhat O(n^2)