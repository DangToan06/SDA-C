#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Student
{
    int id;
    char name[30];
    bool status;
    int avg;
} Student;

typedef struct Node
{
    Student *data;
    struct Node *next;
} Node;

Node *createNode(Student *student)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (Student *)malloc(sizeof(Student));
    newNode->data->id = student->id;
    strcpy(newNode->data->name, student->name);
    newNode->data->status = student->status;
    newNode->data->avg = student->avg;
    newNode->next = NULL;
    return newNode;
}

Node *addNode(Node *root, Student *student)
{
    Node *newNode = createNode(student);

    if (root == NULL)
    {
        return newNode;
    }

    newNode->next = root;
    return newNode;
}

void printNode(Node *root)
{
    if (root != NULL)
    {
        Node *current = root;
        while (current != NULL)
        {
            printf("Id: %d || Name: %s || Status: %s || Avg: %d\n",
                   current->data->id,
                   current->data->name,
                   current->data->status ? "true" : "false",
                   current->data->avg);
            current = current->next;
        }
    }
    else
    {
        printf("List is empty.\n");
    }
}

Node *removeNode(Node *root, int id)
{
    if (root == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    Node *current = root;
    Node *previous = NULL;

    while (current != NULL && current->data->id != id)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Student with ID %d not found.\n", id);
        return root;
    }

    if (previous == NULL)
    {
        Node *temp = root;
        root = root->next;
        free(temp->data);
        free(temp);
    }
    else
    {
        previous->next = current->next;
        free(current->data);
        free(current);
    }

    return root;
}

Node *updateNode(Node *root, int id, Student *student)
{
    Node *current = root;

    while (current != NULL)
    {
        if (current->data->id == id)
        {
            current->data->id = student->id;
            strcpy(current->data->name, student->name);
            current->data->avg = student->avg;
        }
    }
    return root;
}

void changeStatus(Node *root, int id)
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->data->id == id)
        {
            current->data->status = !current->data->status;
            printf("Status changed successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found.\n", id);
}

Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *result = NULL;
    if (a->data->avg <= b->data->avg)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void split(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast = source->next;
    Node *slow = source;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void mergeSort(Node **headRef)
{
    Node *head = *headRef;
    if (!head || !head->next)
        return;

    Node *a, *b;
    split(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);

    *headRef = merge(a, b);
}

Node *binarySearch(Node *root, int id)
{
    int size = 0;
    Node *temp = root;
    while (temp)
    {
        size++;
        temp = temp->next;
    }

    Node **arr = (Node **)malloc(size * sizeof(Node *));
    temp = root;
    for (int i = 0; i < size; i++)
    {
        arr[i] = temp;
        temp = temp->next;
    }

    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid]->data->id == id)
            return arr[mid];
        else if (arr[mid]->data->id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return NULL;
}

void menu()
{
    system("cls");
    printf("----------STUDENTS MANAGER----------\n");
    printf("1. Add student\n");
    printf("2. Display student\n");
    printf("3. Remove student\n");
    printf("4. Update student\n");
    printf("5. Change stautus\n");
    printf("6. Sort student\n");
    printf("7. Search student\n");
    printf("8. Exit\n");
    printf("Choice: \n");
}

int main()
{
    int choice;
    Student student;
    Node *root = NULL;
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("Enter student ID: \n");
            scanf("%d", &student.id);
            printf("Enter name student: \n");
            getchar();
            fgets(student.name, sizeof(student.name), stdin);
            student.name[strcspn(student.name, "\n")] = '\0';
            printf("Enter student avg: \n");
            scanf("%d", &student.avg);
            printf("Enter status student (1/0): \n");
            int temp;
            scanf("%d", &temp);
            student.status = temp;
            root = addNode(root, &student);
            printf("Add student success!\n");
            getchar();
            getchar();
            break;
        case 2:
            system("cls");
            printNode(root);
            printf("Print student success!!\n");
            getchar();
            getchar();
            break;
        case 3:
            system("cls");
            printf("Enter syudent ID to remove:\n");
            int id;
            scanf("%d", &id);
            root = removeNode(root, id);
            printf("Remove student success!\n");
            getchar();
            getchar();
            break;
        case 4:
            system("cls");
            printf("Enter student ID to update:\n");
            int updateId;
            scanf("%d", &updateNode);
            printf("Enter new name student:\n");
            getchar();
            fgets(student.name, sizeof(student.name), stdin);
            student.name[strcspn(student.name, "\n")] = '0';
            printf("Enter new student avg:\n");
            scanf("%d", &student.avg);
            root = updateNode(root, updateId, &student);
            printf("update success!\n");
            getchar();
            getchar();
            break;
        case 5:
            system("cls");
            printf("Enter student ID to change status:\n");
            scanf("%d", &id);
            changeStatus(root, id);
            getchar();
            getchar();
            break;

        case 6:
            system("cls");
            mergeSort(&root);
            printf("Sorted successfully.\n");
            getchar();
            getchar();
            break;

        case 7:
            system("cls");
            printf("Enter student ID to search:\n");
            scanf("%d", &id);
            Node *found = binarySearch(root, id);
            if (found)
            {
                printf("Found student: Id: %d || Name: %s || Status: %s || Avg: %d\n",
                       found->data->id,
                       found->data->name,
                       found->data->status ? "true" : "false",
                       found->data->avg);
            }
            else
            {
                printf("Student not found.\n");
            }
            getchar();
            getchar();
            break;
        default:
            break;
        }
    } while (choice != 8);
    return 0;
}