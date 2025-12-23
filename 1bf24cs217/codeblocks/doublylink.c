#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n)
{
    if (n <= 0) {
        printf("n should be > 0\n");
        return;
    }

    struct node *newnode, *temp = NULL;
    int data;

    for (int i = 1; i <= n; i++) {
        newnode = (struct node*) malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            newnode->prev = NULL;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
        }

        temp = newnode;
    }
}

void InsertBeginning(int item)
{
    struct node *ptr = (struct node*) malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    ptr->data = item;
    ptr->prev = NULL;
    ptr->next = head;

    if (head != NULL)
        head->prev = ptr;

    head = ptr;
}

void InsertLeft(int pos, int item)
{
    if (pos <= 1) {
        InsertBeginning(item);
        return;
    }

    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range\n");
            free(ptr);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(ptr);
        return;
    }

    ptr->data = item;
    ptr->next = temp->next;
    ptr->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = ptr;

    temp->next = ptr;
}

void DeleteSpecific()
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    struct node *temp = head;

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev == NULL) {           
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    } 
    else {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted.\n");
}

void display()
{
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


int main()
{
    int ch, data, pos, n;

    while (1) {
        printf("\n1. Create\n2. Insert at beginning\n3. Insert left of position\n4. Delete specific value\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                InsertBeginning(data);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                InsertLeft(pos, data);
                break;

            case 4:
                DeleteSpecific();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
