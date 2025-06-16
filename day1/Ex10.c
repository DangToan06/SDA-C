#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// CÁCH 1
bool check(char string1[100], char string2[100], int size1, int size2)
{
    if (size1 != size2)
    {
        return false;
    }

    for (int i = 0; i < size1; i++)
    {
        bool checkCharater = false;
        for (int j = 0; j < size2; j++)
        {
            if (string1[i] == string2[j])
            {
                checkCharater = true;
            }
        }
        if (!checkCharater)
        {
            return false;
        }
    }
    return true;
}
// ĐỘ PHỨC TẠP O(n^2)

// CÁCH 2
void meger(char string[100], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int x[n1];
    int y[n2];

    for (int i = 0; i < n1; i++)
    {
        x[i] = string[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        y[i] = string[mid + 1 + i];
    }

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (x[i] < y[j])
        {
            string[left] = x[i];
            left++;
            i++;
        }
        else
        {
            string[left] = y[j];
            left++;
            j++;
        }
    }

    while (i < n1)
    {
        string[left] = x[i];
        left++;
        i++;
    }

    while (j < n2)
    {
        string[left] = y[j];
        left++;
        j++;
    }
}

void megerSort(char string[100], int left, int right)
{
    if (left < right)
    {
        int mid = (right + left) / 2;
        megerSort(string, left, mid);
        megerSort(string, mid + 1, right);
        meger(string, left, mid, right);
    }
}

bool check2(char string1[100], char string2[100], int size1, int size2)
{
    if (size1 != size2)
    {
        return false;
    }

    for (int i = 0; i < size1; i++)
    {
        if (string1[i] != string2[i])
        {
            return false;
        }
    }
    return true;
}

// ĐỘ PHỨC TẠP O(nlogn)

int main()
{
    char string1[100];
    char string2[100];

    scanf("%s", &string1);
    scanf("%s", &string2);

    int len1 = strlen(string1);
    int len2 = strlen(string2);

    if (check(string1, string2, len1, len2))
    {
        printf("t1");
    }
    else
    {
        printf("f1");
    }
    printf("\n");
    megerSort(string1, 0, len1 - 1);
    megerSort(string2, 0, len2 - 1);

    if (check2(string1, string2, len1, len2))
    {
        printf("t2");
    }
    else
    {
        printf("f2");
    }

    return 0;
}