#include <stdio.h>

int redundancy(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * redundancy(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        return printf("Khong hop le");
    }
    printf("%d", redundancy(n));
    return 0;
}