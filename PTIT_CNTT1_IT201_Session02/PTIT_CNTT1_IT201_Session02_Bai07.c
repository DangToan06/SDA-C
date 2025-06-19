#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 200001
#define SETOFF 100000

int searchSum(int *arr, int n, int target)
{
    bool hash[MAX] = {false};

    for (int i = 0; i < n; i++)
    {
        int temp = target - arr[i];
        if (temp >= -SETOFF && temp <= SETOFF && hash[temp + SETOFF])
        {
            return printf("%d %d", arr[i], temp);
        }
        hash[arr[i] + SETOFF] = true;
    }

    return printf("Khong tim thay");
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

    searchSum(arr, n, target);
    free(arr);
    return 0;
}