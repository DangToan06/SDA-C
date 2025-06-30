#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(char arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[flag])
            {
                flag = j;
            }
        }
        swap(&arr[i], &arr[flag]);
    }
}

int main()
{
    char str[10000];
    scanf("%s", str);
    if (strlen(str) == 0)
    {
        printf("Khong hop le");
        return 0;
    }

    selectionSort(str, strlen(str));

    printf("%s", str);

    return 0;
}