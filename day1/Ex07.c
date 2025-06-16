#include <stdio.h>
#include <stdbool.h>

#define MAX 1000000

// CÁCH 1

int check(int a[], int n)
{
    int arr2[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == arr2[j])
            {
                return 0;
            }
            else
            {
                arr2[j] = a[i];
            }
        }
    }
    return 1;
} // ĐỘ PHỨC TẠP O(n^2)

// CÁCH 2

int check2(int a[], int n)
{
    bool seen[MAX] = {false};

    for (int i = 0; i < n; i++)
    {
        if (seen[a[i]] == true)
        {
            return true;
        }
        seen[a[i]] = true;
    }

    return false;
} // ĐỘ PHỨC TẠP O(n)

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    return 0;
}