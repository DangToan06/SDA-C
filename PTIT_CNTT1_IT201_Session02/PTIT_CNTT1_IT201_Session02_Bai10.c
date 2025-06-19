#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check(int a[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == num)
        {
            return false;
        }
    }
    return true;
}

void count(int *a, int n)
{
    int count = 0;
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        if (check(arr2, count, a[i]))
        {
            arr2[count] = a[i];
            count++;
        }
    }

    int countDuplicate[count];
    int k = 0;

    for (int i = 0; i < count; i++)
    {
        int dem = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr2[i] == a[j])
            {
                dem++;
            }
        }
        countDuplicate[k++] = dem;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Phan tu %d xuat hien %d lan\n", arr2[i], countDuplicate[i]);
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

    count(arr, n);

    return 0;
}