#include <stdio.h>

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 10 + sum(n / 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    int tmp = sum(n);
    if (tmp == 0)
    {
        printf("Khong hop le");
        return 0;
    }
    printf("%d", tmp);

    return 0;
}