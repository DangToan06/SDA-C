#include <stdio.h>
#include <stdlib.h>

int average(int *arr, int n)
{
    int count = 0;
    int avg = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            avg += arr[i];
            count++;
        }
    }

    return avg / count;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        return printf("So luong phan tu khong hop le");
    }
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int avg = average(arr, n);

    printf("average = %d", avg);

    free(arr);
    return 0;
}