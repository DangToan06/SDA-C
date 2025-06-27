#include <stdio.h>

int countPath(int i, int j, int rows, int cols)
{
    if (i >= rows || j >= cols)
    {
        return 0;
    }
    if (i == rows - 1 && j == cols - 1)
    {
        return 1;
    }

    return countPath(i + 1, j, rows, cols) + countPath(i, j + 1, rows, cols);
}

int main()
{

    int rows, cols;

    scanf("%d %d", &rows, &cols);

    printf("%d", countPath(0, 0, rows, cols));
    return 0;
}