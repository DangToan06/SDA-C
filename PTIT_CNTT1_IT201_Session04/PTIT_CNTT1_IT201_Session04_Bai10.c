#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct
{
    int id;
    char name[10];
    int age;
} Student;

void strToLower(char *dest, const char *src)
{
    while (*src)
    {
        *dest = tolower(*src);
        dest++;
        src++;
    }
    *dest = '\0';
}

int main()
{
    int n;
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++)
    {
        students[i].id = i + 1;
        scanf("%s", students[i].name);
        scanf("%d", &students[i].age);
    }

    for (int i = 0; i < n; i++)
    {
        printf("id: %d || Ho ten: %s || Tuoi: %d\n", students[i].id, students[i].name, students[i].age);
    }

    char search[10];
    bool check = false;
    printf("Nhap vao ten ban muon tim kiem:\n");
    scanf("%s", search);

    char searchLower[50];
    strToLower(searchLower, search);

    for (int i = 0; i < n; i++)
    {
        char nameLower[50];
        strToLower(nameLower, students[i].name);
        if (strstr(nameLower, searchLower))
        {
            check = true;
            printf("id: %d || Ho ten: %s || Tuoi: %d\n", students[i].id, students[i].name, students[i].age);
        }
    }

    if (!check)
    {
        printf("Khong tim thay");
    }

    free(students);
    return 0;
}
