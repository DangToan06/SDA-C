#include <stdio.h>
#include <stdlib.h>

void sorting(int arr[], int n)
{
    int arrPrositive[100000];
    int arrZero[100000];
    int arrVowel[100000];
    int l = 0, m = 0, k = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            arrVowel[l++] = arr[i];
        }
        else if (arr[i] > 0)
        {
            arrPrositive[m++] = arr[i];
        }
        else
        {
            arrZero[k++] = arr[i];
        }
    }

    int index = 0;
    for (int i = 0; i < l; i++)
    {
        arr[index++] = arrVowel[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[index++] = arrZero[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr[index++] = arrPrositive[i];
    }
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

    sorting(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}