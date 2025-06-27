#include <stdio.h>
#include <stdlib.h>

int sumArry(int n, int arr[])
{
    if (n == 0)
    {
        return 0;
    }

    return arr[n - 1] + sumArry(n - 1, arr);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        return printf("Khong hop le");
    }
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", sumArry(n, arr));

    return 0;
}