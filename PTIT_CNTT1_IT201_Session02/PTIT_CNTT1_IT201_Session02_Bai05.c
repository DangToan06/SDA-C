#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int size = sizeof arr / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int position;
    scanf("%d", &position);
    if (position < 0 || position > n)
    {
        return printf("Vi tri khong hop le");
    }
    for (int i = position; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }

    int *temp = realloc(arr, (--n) * sizeof(int));

    arr = temp;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}