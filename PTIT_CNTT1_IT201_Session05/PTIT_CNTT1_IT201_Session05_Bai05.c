#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkString(char str[100], int i, int size)
{
    if (i >= size / 2)
    {
        return true;
    }

    if (str[i] != str[size - i])
    {
        return false;
    }

    return checkString(str, i + 1, size);
}

int main()
{
    char str[100];
    fgets(str, 100, stdin);

    int size = strlen(str) - 1;
    int i = 0;

    if (checkString(str, i, size))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}