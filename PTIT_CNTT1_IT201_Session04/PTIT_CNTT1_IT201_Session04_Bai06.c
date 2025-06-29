#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
    int id;
    char name[10];
    int age;
} Student;

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

    int search;
    bool check = false;
    printf("Nhap vao id ban muon tim kiem:\n");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {
        if (students[i].id == search)
        {
            check = true;
            return printf("id: %d || Ho ten: %s || Tuoi: %d\n", students[i].id, students[i].name, students[i].age);
        }
    }

    if (!check)
    {
        printf("Khong tim thay");
    }

    free(students);
    return 0;
}
