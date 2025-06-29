#include <stdio.h>

void fibo(int n, int fibo1, int fibo2, int *count)
{
    *count += 1;
    if (*count > n)
        return;
    fibo(n, fibo2, fibo1 + fibo2, count);
    printf("%d ", fibo2);
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
    int count = 0;
    fibo(n, fibo1, fibo2, &count);
    return 0;
}