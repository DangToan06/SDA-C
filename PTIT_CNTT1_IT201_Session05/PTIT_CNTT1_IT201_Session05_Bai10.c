#include <stdio.h>

int countPath(int i, int j, int rows, int cols, int blockRow, int blockCol)
{
    if (i == rows - 1 && j == cols - 1)
    {
        return 1;
    }

    if (i >= rows || j >= cols || (i == blockRow && j == blockCol))
    {
        return 0;
    }

    return countPath(i + 1, j, rows, cols, blockRow, blockCol) + countPath(i, j + 1, rows, cols, blockRow, blockCol);
}

int main()
{
    int rows, cols;

    scanf("%d %d", &rows, &cols);

    int blockRow, blockCol;

    scanf("%d %d", &blockRow, &blockCol);

    printf("%d", countPath(0, 0, rows, cols, blockRow, blockCol));
    return 0;
}