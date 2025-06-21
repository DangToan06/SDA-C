#include <stdio.h>
#include <stdlib.h>

void calc(int **arr, int rows, int cols)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < rows; i++)
    {
        sum1 += arr[i][i];
    }

    for (int i = 0; i < cols; i++)
    {
        sum2 += arr[i][cols - 1 - i];
    }

    printf("Thong duong cheo chinh: %d\n Tong duong cheo phu: %d", sum1, sum2);
}

int main()
{
    int rows, cols;
    printf("Nhap so hang va cot: \n");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 && cols <= 0)
    {
        return printf("Hang va cot khong hop le");
    }
    else if (rows <= 0)
    {
        return printf("Hang khong hop le");
    }
    else if (cols <= 0)
    {
        return printf("Cot khong hop le");
    }
    else if (rows != cols)
    {
        return printf("mang khong co duong cheo chinh va duong cheo phu");
    }

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    calc(arr, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}