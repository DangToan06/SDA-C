#include <stdio.h>

void printArr(int a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // ĐỘ PHỨC TẠP KHÔNG GIAN O(1)
    // ĐỘ PHỨC TẠP THỜI GIAN O(n^2)
}

void printDiagonal(int a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", a[i][i]);
        // ĐỘ PHỨC TẠP KHÔNG GIAN O(1)
        // ĐỘ PHỨC TẠP THỜI GIAN O(n)
    }
}

int main()
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printArr(a);
    printf("\n");
    printDiagonal(a);
    return 0;
}