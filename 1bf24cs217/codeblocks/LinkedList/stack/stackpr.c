#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

    printf("Pushed %d\n", new_data);
}

void pop(struct Node** head_ref)
{
    struct Node* ptr;

    if (*head_ref == NULL) {
        printf("Stack is empty\n");
        return;
    }

    ptr = *head_ref;
    *head_ref = ptr->next;

    printf("Popped %d\n", ptr->data);

    free(ptr);
}

void display(struct Node* head)
{
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node* stack = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                display(stack);
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

