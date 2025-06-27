#include <stdio.h>

void print(int n, int count)
{
    printf("%d ", count);
    if (count >= n)
        return;
    print(n, count + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    print(n, 1);
    return 0;
}