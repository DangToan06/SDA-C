#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int swapInterger(char str[], int i, int size)
{

    if (i >= size)
        return 0;

    return (str[i] - '0') * pow(10, size - 1 - i) + swapInterger(str, i + 1, size);
}

int main()
{
    char str[100];

    scanf("%s", str);

    int size = strlen(str);
    int i = 0;

    for (int i = 0; i < size; i++)
    {
        char temp = tolower(str[i]);
        if (strchr("abcdefghijklmnopqrstyvwxyz", temp))
        {
            printf("Input khong hop le");
            return 0;
        }
    }

    printf("%d", swapInterger(str, i, size));

    return 0;
}