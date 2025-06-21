#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Nhap so luongw phan tu lan 1: \n");
    scanf("%d", &n);

    if (n < 0)
    {
        return printf("So luong phan tu khong hop le");
    }

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int m;
    printf("Nhap so luong phan tu lan 2: \n");
    scanf("%d", &m);

    if (m < 0)
    {
        return printf("So luong phan tu khong hop le");
    }

    int *temp = (int *)realloc(arr, (m + n) * sizeof(int));
    arr = temp;
    for (int i = n; i < m + n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Mang cua ban la: \n");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}