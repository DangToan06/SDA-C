#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct Course
{
    int id;
    char title[30];
    int credit;
} Course;

typedef struct Node
{
    Course data;
    struct Node *next;
} Node;

typedef struct Node2
{
    Course data;
    struct Node2 *next;
    struct Node2 *prev;
} Node2;

Course *createCourse()
{
    Course *course = (Course *)malloc(sizeof(Course));
    course->id = 0;
    course->title[0] = '\0';
    course->credit = 0;
    return course;
}

Node *addCourse(Node *head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data.id = rand() % 1000 + 1;

    printf("Enter name course: ");
    fgets(newNode->data.title, sizeof(newNode->data.title), stdin);
    newNode->data.title[strcspn(newNode->data.title, "\n")] = '\0';

    printf("Enter credit: ");
    scanf("%d", &newNode->data.credit);
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void displayNode(Node *head)
{
    if (head == NULL)
    {
        printf("List course not exists\n");
        return;
    }

    printf("List of courses:\n");
    Node *current = head;
    while (current != NULL)
    {
        printf("ID: %d | Title: %s | Credit: %d\n",
               current->data.id,
               current->data.title,
               current->data.credit);
        current = current->next;
    }
}

Node *deleteCourse(Node *head)
{
    if (head == NULL)
    {
        printf("List of course:\n");
        return head;
    }

    Node *temp = head;

    if (head->next != NULL)
    {
        head = head->next;
    }
    else
    {
        head = NULL;
    }

    free(temp);
    return head;
}

void updateNode(Node *head, int pos)
{
    if (head == NULL)
    {
        printf("List of course:\n");
        return;
    }

    Node *current = head;

    char titleValue[30];
    int creditValue;

    printf("Update title:\n");
    getchar();
    fgets(titleValue, sizeof(titleValue), stdin);
    titleValue[strcspn(titleValue, "\n")] = '\0';
    printf("Update credit:\n");
    scanf("%d", &creditValue);

    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }

    strcpy(current->data.title, titleValue);
    current->data.credit = creditValue;
}

void menu()
{
    system("cls");
    printf("----------Course Manager----------\n");
    printf("1. Add course\n");
    printf("2. Display course\n");
    printf("3. Delete course\n");
    printf("4. Update course\n");
    printf("5. Mark course as complete\n");
    printf("6. Sort course\n");
    printf("7. Search course\n");
    printf("8. Exit\n");
    printf("Your choice: ");
}
int main()
{
    int choice;
    srand(time(NULL));
    Node *head = NULL;
    do
    {
        menu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            system("cls");
            head = addCourse(head);
            printf("Add success\n");
            getchar();
            break;
        case 2:
            system("cls");
            displayNode(head);
            getchar();
            break;
        case 3:
            system("cls");
            head = deleteCourse(head);
            printf("Delete success\n");
            getchar();
            break;
        case 4:
            system("cls");
            int pos;
            printf("Enter position update:\n");
            scanf("%d", &pos);
            updateNode(head, pos);
            getchar();
        default:
            break;
        }
    } while (choice != 8);

    return 0;
}