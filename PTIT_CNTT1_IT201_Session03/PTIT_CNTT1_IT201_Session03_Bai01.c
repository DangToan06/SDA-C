#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 0)
    {
        return printf("So luong phan tu khong duoc am");
    }
    else if (n == 0)
    {
        return printf("So luong phan tu phai lon hon 0");
    }
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("So thu %d = %d\n", i + 1, arr[i]);
    }

    free(arr);
    return 0;
}