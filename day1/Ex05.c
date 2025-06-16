#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < 6; i++)
    {
        bool checkSort = false;
        for (int j = 0; j < 6 - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                checkSort = true;
            }
        }

        if (!checkSort)
        {
            break;
        }
    }
}

void meger(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            a[left] = L[i];
            ++i;
            ++left;
        }
        else
        {
            a[left] = R[j];
            ++j;
            ++left;
        }
    }

    while (i < n1)
    {
        a[left] = L[i];
        ++i;
        ++left;
    }

    while (j < n2)
    {
        a[left] = R[j];
        ++j;
        ++left;
    }
}

void megerSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        megerSort(a, left, mid);
        megerSort(a, mid + 1, right);
        meger(a, left, mid, right);
    }
}

int main()
{
    int a[6] = {3, 5, 7, 2, 1, 4};
    int n = 6;

    bubbleSort(a, n); // ĐỘ PHỨC TẠP O(n^2);

    megerSort(a, 0, 5); // ĐỘ PHỨC TẠP O(nlogn);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}