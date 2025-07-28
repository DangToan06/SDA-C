#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order
{
    int id;
    char customer[30];
    int status;
    char total[30];
} Order;

typedef struct Node1
{
    Order data;
    struct Node1 *next;
} Node1;

typedef struct Node2
{
    Order data;
    struct Node2 *next;
    struct Node2 *prev;
} Node2;

Node2 *createNode2(Order order)
{
    Node2 *newNode = (Node2 *)malloc(sizeof(Node2));
    newNode->data = order;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Node2 *addNode2(Node2 *root, Order order)
{
    Node2 *newNode = createNode2(order);
    if (root == NULL)
    {
        return newNode;
    }

    newNode->next = root;
    root->prev = newNode;

    return newNode;
}

void printNode(Node2 *root2, Node1 *root1)
{
    if (root2 == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node2 *current2 = root2;
    printf("----------List order----------\n");
    while (current2 != NULL)
    {
        printf("Id: %d || Customer: %s || Status: %d || Total: %s\n",
               current2->data.id,
               current2->data.customer,
               current2->data.status,
               current2->data.total);
        current2 = current2->next;
    }

    if (root1 == NULL)
    {
        printf("List check is empty!\n");
        return;
    }

    Node1 *current = root1;
    printf("----------List order check----------\n");
    while (current != NULL)
    {
        printf("Id: %d || Customer: %s || Status: %d || Total: %s\n",
               current->data.id,
               current->data.customer,
               current->data.status,
               current->data.total);
        current = current->next;
    }
}

Node2 *removeNodeById(Node2 *root, int id)
{
    Node2 *current = root;

    while (current != NULL)
    {
        if (current->data.id == id)
        {
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                root = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current);
            printf("Order with ID %d removed successfully.\n", id);
            return root;
        }
        current = current->next;
    }

    printf("Order with ID %d not found.\n", id);
    return root;
}

void updateOrder(Node2 *root)
{
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    getchar();

    Node2 *current = root;
    while (current != NULL)
    {
        if (current->data.id == id)
        {
            printf("Enter new customer name: ");
            fgets(current->data.customer, sizeof(current->data.customer), stdin);
            current->data.customer[strcspn(current->data.customer, "\n")] = '\0';

            printf("Enter new total cost: ");
            fgets(current->data.total, sizeof(current->data.total), stdin);
            current->data.total[strcspn(current->data.total, "\n")] = '\0';

            printf("Update successful.\n");
            return;
        }
        current = current->next;
    }

    printf("Order with ID %d not found.\n", id);
}

Node1 *createNode1(Order order)
{
    Node1 *newNode = (Node1 *)malloc(sizeof(Node1));
    newNode->data = order;
    newNode->next = NULL;
    return newNode;
}

Node1 *addNode1(Node1 *root, Order order)
{
    Node1 *newNode = createNode1(order);
    newNode->next = root;
    return newNode;
}

Node2 *markDelivered(Node2 *root2, Node1 **root1)
{
    int id;
    printf("Enter ID to mark as delivered: ");
    scanf("%d", &id);
    getchar();

    Node2 *current = root2;

    while (current != NULL)
    {
        if (current->data.id == id)
        {
            *root1 = addNode1(*root1, current->data);

            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                root2 = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current);
            printf("Order marked as delivered.\n");
            return root2;
        }
        current = current->next;
    }

    printf("Order with ID %d not found.\n", id);
    return root2;
}

Node2 *sortOrders(Node2 *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    Node2 *i, *j;
    for (i = root; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (atoi(i->data.total) > atoi(j->data.total))
            {
                Order temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Orders sorted by total cost.\n");
    return root;
}

void searchOrder(Node2 *root2, Node1 *root1)
{
    char name[30];
    printf("Enter customer name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;

    printf("--- Pending Orders ---\n");
    Node2 *current2 = root2;
    while (current2 != NULL)
    {
        if (strcmp(current2->data.customer, name) == 0)
        {
            printf("Id: %d || Customer: %s || Status: %d || Total: %s\n",
                   current2->data.id,
                   current2->data.customer,
                   current2->data.status,
                   current2->data.total);
            found = 1;
        }
        current2 = current2->next;
    }

    printf("--- Delivered Orders ---\n");
    Node1 *current1 = root1;
    while (current1 != NULL)
    {
        if (strcmp(current1->data.customer, name) == 0)
        {
            printf("Id: %d || Customer: %s || Status: %d || Total: %s\n",
                   current1->data.id,
                   current1->data.customer,
                   current1->data.status,
                   current1->data.total);
            found = 1;
        }
        current1 = current1->next;
    }

    if (!found)
        printf("No order found for customer: %s\n", name);
}

void menu()
{
    system("cls");
    printf("----------ORDER MANAGER----------\n");
    printf("1. Add order\n");
    printf("2. Display order\n");
    printf("3. Remove order\n");
    printf("4. Update order\n");
    printf("5. Mark order\n");
    printf("6. Sort order\n");
    printf("7. Search order\n");
    printf("8. Exit\n");
    printf("Enter your choice:\n");
}

int main()
{
    int choice;
    Node1 *root1 = NULL;
    Node2 *root2 = NULL;
    Order order;
    do
    {
        menu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            system("cls");
            printf("Enter id order:\n");
            scanf("%d", &order.id);
            getchar();
            printf("Enter name customer:\n");
            fgets(order.customer, sizeof(order.customer), stdin);
            order.customer[strcspn(order.customer, "\n")] = '\0';
            printf("Enter status(1/0):\n");
            scanf("%d", &order.status);
            getchar();
            printf("Enter cost:\n");
            fgets(order.total, sizeof(order.total), stdin);
            order.total[strcspn(order.total, "\n")] = '\0';
            root2 = addNode2(root2, order);
            printf("Add success\n");
            getchar();
            break;
        case 2:
            system("cls");
            printNode(root2, root1);
            printf("print success\n");
            getchar();
            break;
        case 3:
            system("cls");
            printf("Enter ID to remove: ");
            int removeId;
            scanf("%d", &removeId);
            root2 = removeNodeById(root2, removeId);
            getchar();
            break;
        case 4:
            system("cls");
            updateOrder(root2);
            getchar();
            break;
        case 5:
            system("cls");
            root2 = markDelivered(root2, &root1);
            getchar();
            break;
        case 6:
            system("cls");
            root2 = sortOrders(root2);
            getchar();
            break;
        case 7:
            system("cls");
            searchOrder(root2, root1);
            getchar();
            break;
        case 8:
            printf("Goodbye!\n");
            break;
        default:
            break;
        }
    } while (choice != 8);

    return 0;
}