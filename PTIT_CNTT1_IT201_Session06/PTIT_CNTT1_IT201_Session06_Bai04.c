#include <stdio.h>

void townOfHanoi(int n, char a, char c, char b)
{
    if (n == 0)
    {
        return;
    }

    townOfHanoi(n - 1, a, b, c);
    printf("Dia %d di chuyen tu %c sang %c\n", n, a, c);
    townOfHanoi(n - 1, b, c, a);
}

int main()
{
    int n;
    scanf("%d", &n);

    townOfHanoi(n, 'A', 'C', 'B');
    return 0;
}