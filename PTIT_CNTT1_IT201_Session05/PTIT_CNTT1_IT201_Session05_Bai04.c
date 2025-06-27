#include <stdio.h>

int sum(int n, int m)
{
    if (n > m)
    {
        return 0;
    }
    return m + sum(n, m - 1);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (n < 0 || m < 0)
    {
        return printf("Khong hop le");
    }

    if (n == m)
    {
        return printf("%d", n);
    }

    if (n < m)
    {
        printf("%d", sum(n, m));
    }
    else
    {
        printf("%d", sum(m, n));
    }

    return 0;
}