#include <stdio.h>
#include <stdlib.h>

void findMinMax(int **arr, int rows, int cols)
{
    int min = arr[0][0];
    int max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    printf("max = %d\n", max);
    printf("min = %d", min);
}

int main()
{
    int rows, cols;
    printf("Nhap so hang va cot:\n");
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
        arr[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findMinMax(arr, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}