
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Enqueue function (insert at end)
void Enqueue(struct Node** head_ref, int item)
{
    struct Node *ptr, *temp;

    ptr = (struct Node*) malloc(sizeof(struct Node));
    if (!ptr) {
        printf("Memory allocation failed\n");
        return;
    }

    ptr->data = item;
    ptr->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = ptr;
        printf("Node inserted: %d\n", item);
    }
    else {
        temp = *head_ref;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = ptr;
        printf("Node inserted: %d\n", item);
    }
}

// Dequeue function (delete from beginning)
void Dequeue(struct Node** head_ref)
{
    struct Node* ptr;

    if (*head_ref == NULL) {
        printf("Queue is empty\n");
        return;
    }

    ptr = *head_ref;
    *head_ref = ptr->next;

    printf("Node deleted from beginning: %d\n", ptr->data);
    free(ptr);
}

// Display queue
void Display(struct Node* head)
{
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main()
{
    struct Node* queue = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                Enqueue(&queue, value);
                break;

            case 2:
                Dequeue(&queue);
                break;

            case 3:
                Display(queue);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
