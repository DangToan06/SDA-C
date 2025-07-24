#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Task
{
    int id;
    char title[30];
    int priority;
    char deadline[30];
} Task;

typedef struct Node
{
    Task data;
    struct Node *next;
} Node;

typedef struct Node2
{
    Task data;
    struct Node2 *next;
    struct Node2 *prev;
} Node2;

Node *createNode(Task *task)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data.id = task->id;
    strcpy(newNode->data.title, task->title);
    newNode->data.priority = task->priority;
    strcpy(newNode->data.deadline, task->deadline);
    newNode->next = NULL;
    return newNode;
}

void displayTasks(Node *head)
{
    if (head == NULL)
    {
        printf("No tasks available.\n");
        return;
    }
    Node *current = head;
    printf("List of tasks:\n");
    while (current != NULL)
    {
        printf("ID: %d | Title: %s | Priority: %d | Deadline: %s\n",
               current->data.id,
               current->data.title,
               current->data.priority,
               current->data.deadline);
        current = current->next;
    }
}

int randomId()
{
    srand(time(NULL));
    return rand() % 1000 + 1;
}

Node *addTask(Node *head, Task *task)
{
    Node *newNode = createNode(task);
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

Node2 *addTask2(Node2 *head, Task *task)
{
    Node2 *newNode = (Node2 *)malloc(sizeof(Node2));
    newNode->data.id = task->id;
    strcpy(newNode->data.title, task->title);
    newNode->data.priority = task->priority;
    strcpy(newNode->data.deadline, task->deadline);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    Node2 *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

void removeTask(Node *head, int id)
{
    if (head == NULL)
    {
        printf("No tasks to remove.\n");
        return;
    }

    Node *current = head;
    Node *prev = NULL;

    while (current != NULL && current->data.id != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Task with ID %d not found.\n", id);
        return;
    }

    if (current == head)
    {
        Node *temp = head->next;
        head = head->next;
        free(temp);
        return;
    }

    Node *temp = current;
    prev->next = temp->next;
    free(temp);
}

void updateTask(Node *head, int id)
{
    if (head == NULL)
    {
        printf("No tasks to update.\n");
        return;
    }
    Node *current = head;
    while (current != NULL && current->data.id != id)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Task with ID %d not found.\n", id);
        return;
    }

    char titleValue[30];
    int priorityValue;
    printf("Update title:\n");
    fgets(titleValue, sizeof(titleValue), stdin);
    titleValue[strcspn(titleValue, "\n")] = '\0';
    printf("Update priority:\n");
    scanf("%d", &priorityValue);
    getchar();
    strcpy(current->data.title, titleValue);
    current->data.priority = priorityValue;
    printf("Task updated successfully!\n");

    printf("Updated Task: ID: %d | Title: %s | Priority: %d | Deadline: %s\n",
           current->data.id,
           current->data.title,
           current->data.priority,
           current->data.deadline);
    getchar();
}

void sortNode(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *minNode = current;
        Node *nextNode = current->next;

        while (nextNode != NULL)
        {
            if (minNode->data.priority > nextNode->data.priority)
            {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        if (minNode != current)
        {
            Task temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }

        current = current->next;
    }
}

Node *pivotTask(Node *head, int id)
{
    if (head == NULL)
    {
        printf("No tasks available to pivot.\n");
        return head;
    }

    Node *current = head;
    while (current != NULL && current->data.id != id)
    {
        current = current->next;
    }
    return current;
}

Node *searchTask(Node *head, int id)
{
    if (head == NULL)
    {
        printf("No tasks available to search.\n");
        return NULL;
    }

    Node *current = head;
    while (current != NULL)
    {
        if (current->data.id == id)
        {
            printf("Task found: ID: %d | Title: %s | Priority: %d | Deadline: %s\n",
                   current->data.id,
                   current->data.title,
                   current->data.priority,
                   current->data.deadline);
            return current;
        }
        current = current->next;
    }
    printf("Task with ID %d not found.\n", id);
    return NULL;
}

void menu()
{
    // system("cls");
    printf("----------TASK MANAGEMENT----------\n");
    printf("1. Add task\n");
    printf("2. Display task\n");
    printf("3. Delete task\n");
    printf("4. Update task\n");
    printf("5. Pivot task\n");
    printf("6. Sort task\n");
    printf("7. Search task\n");
    printf("8. Exit\n");
    printf("Choose an option: ");
}

int main()
{
    int choice;
    Node *head = NULL;
    Node2 *head2 = NULL;
    Task task;

    do
    {
        menu();
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            system("cls");
            task.id = randomId();
            printf("Enter task title: ");
            fgets(task.title, sizeof(task.title), stdin);
            task.title[strcspn(task.title, "\n")] = '\0';
            printf("Enter task priority: ");
            scanf("%d", &task.priority);
            getchar();
            printf("Enter task deadline: ");
            fgets(task.deadline, sizeof(task.deadline), stdin);
            task.deadline[strcspn(task.deadline, "\n")] = '\0';
            head = addTask(head, &task);
            printf("Task added successfully!\n");
            getchar();
            break;
        case 2:
            system("cls");
            displayTasks(head);
            getchar();
            break;
        case 3:
            system("cls");
            printf("Enter task ID to delete: ");
            int id;
            scanf("%d", &id);
            removeTask(head, id);
            printf("Task deleted successfully!\n");
            getchar();
            break;
        case 4:
            system("cls");
            printf("Enter task ID to update: ");
            scanf("%d", &task.id);
            getchar();
            updateTask(head, task.id);
            break;
        case 5:
            system("cls");
            if (head == NULL)
            {
                printf("No tasks available to pivot.\n");
                getchar();
                break;
            }
            printf("Enter task ID to pivot: ");
            int pivotId;
            Node *pivotNode = NULL;
            scanf("%d", &pivotId);
            getchar();
            pivotNode = pivotTask(head, pivotId);
            removeTask(head, pivotId);
            head2 = addTask2(head2, &pivotNode->data);
            printf("Task pivoted successfully!\n");
            getchar();
            break;
        case 6:
            system("cls");
            sortNode(head);
            printf("Tasks sorted by priority successfully!\n");
            getchar();
            break;
        case 7:
            system("cls");
            printf("Enter task ID to search: ");
            int searchId;
            scanf("%d", &searchId);
            getchar();
            searchTask(head, searchId);
            getchar();
            break;
        case 8:
            system("cls");
            printf("Exiting the program.\n");
            getchar();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            getchar();
            break;
        }
    } while (choice != 8);

    return 0;
}