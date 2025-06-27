#include <stdio.h>

void fibo(int n, int fibo1, int fibo2, int *count)
{
    *count += 1;
    if (*count > n)
        return;
    printf("%d ", fibo2);
    fibo(n, fibo2, fibo1 + fibo2, count);
}

int main()
{
    int n;
    scanf("%d", &n);
    int fibo1 = 0;
    int fibo2 = 1;

    if (n <= 0)
    {
        return printf("Khong hop le");
    }
    else if (n >= 1)
    {
        printf("0 ");
    }
    int count = 1;
    fibo(n, fibo1, fibo2, &count);
    return 0;
}