#include <stdio.h>
#include <stdlib.h>

void timDoiXung(int *arr, int n)
{
    int check = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == arr[n - 1 - i])
        {
            printf("%d %d\n", arr[i], arr[n - 1 - i]);
            check = 1;
        }
    }
    if (check == 0)
    {
        printf("Khong tim thay phan tu nao");
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

    timDoiXung(arr, n);

    free(arr);
    return 0;
}