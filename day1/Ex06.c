#include <stdio.h>
#include <stdbool.h>

bool check(int a[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == num)
        {
            return false;
        }
    }
    return true;
}

void count(int a[], int n)
{
    int count = 0;
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        if (check(arr2, count, a[i]))
        {
            arr2[count] = a[i];
            count++;
        }
    }

    int countDuplicate[count];
    int k = 0;

    for (int i = 0; i < count; i++)
    {
        int dem = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr2[i] == a[j])
            {
                dem++;
            }
        }
        countDuplicate[k++] = dem;
    }

    for (int i = 0; i < count; i++)
    {
        printf("so lan xuat hien cua %d là %d\n", arr2[i], countDuplicate[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    count(a, n);

    return 0;
}

// ĐỘ PHỨC TẠP THỜI GIAN O(n^2)
// ĐỘ PHỨC TẠP KHÔNG GIAN O(n)