#include <stdio.h>

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n + sum(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        return printf("Khong hop le");
    }
    printf("%d", sum(n));
    return 0;
}