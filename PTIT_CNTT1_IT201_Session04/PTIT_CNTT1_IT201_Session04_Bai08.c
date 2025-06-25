#include <stdio.h>
#include <stdlib.h>

void linearSearch(int *arr, int n, int target)
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            printf("%d ", i);
            check = 1;
        }
    }
    if (check == 0)
    {
        printf("Khong tim thay phan tu");
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

    int target;
    scanf("%d", &target);

    linearSearch(arr, n, target);

    free(arr);
    return 0;
}