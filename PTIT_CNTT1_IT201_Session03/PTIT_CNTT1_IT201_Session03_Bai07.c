#include <stdio.h>
#include <stdlib.h>

int sum(int **arr, int cols, int row)
{
    int sum = 0;
    for (int i = 0; i < cols; i++)
    {
        sum += arr[row - 1][i];
    }

    return sum;
}

int main()
{
    int rows, cols;
    printf("Nhap vao so hang va so cot: \n");
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

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int *));
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int row;
    printf("Nhap so hang ban muon tinh tong\n");
    scanf("%d", &row);

    if (row > rows)
    {
        return printf("Hang ban nhap khong ton tai");
    }

    int sumRow = sum(arr, cols, row);

    printf("Sum: %d", sumRow);

    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}