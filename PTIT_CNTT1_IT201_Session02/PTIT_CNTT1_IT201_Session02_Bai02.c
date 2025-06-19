#include <stdio.h>
#include <stdlib.h>

int countElement(int arr[], int size, int num)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int num;
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int count = countElement(arr, n, num);

    printf("%d", count);
    // free(arr);
    return 0;
}