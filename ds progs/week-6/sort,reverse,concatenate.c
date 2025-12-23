#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *newnode, *temp;
    int data, i;
    if (n <= 0) {
        printf("Number of nodes should be > 0\n");
        return;
    }
    for (i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    printf("Linked list created\n");
}


void reverse() {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully\n");
}


struct node* concatenate(struct node *h1, struct node *h2) {
    struct node *temp;
    if (h1 == NULL) {
        return h2;
    }
    if (h2 == NULL) {
        return h1;
    }
    temp = h1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = h2;
    printf("Lists concatenated\n");
    return h1;
}


void sort() {
    struct node *i, *j;
    int tempdata;
    if (head == NULL) {
        printf("List is empty, cannot sort.\n");
        return;
    }
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tempdata = i->data;
                i->data = j->data;
                j->data = tempdata;
            }
        }
    }
    printf("List sorted successfully\n");
}


void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, n;
    struct node *head2 = NULL;

    do{
        printf("\n");
        printf("1. Creation, 2. Reverse, 3. Concatenation, 4. Sort, 5. Display, 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);


        switch (ch) {

            case 1: {
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;
            }
            case 2: {
                reverse();
                break;
            }
            case 3: {
                printf("Creating second list for concatenation:\n");
                struct node *temp_head_for_concat = head;
                head = NULL;
                printf("Enter number of nodes for second list: ");
                scanf("%d", &n);
                create(n);
                head2 = head;
                head = temp_head_for_concat;

                if (head == NULL && head2 == NULL) {
                    printf("Both lists are empty, nothing to concatenate.\n");
                } else {
                    head = concatenate(head, head2);
                break;
            }
            case 4: {
                sort();
                break;
            }
            case 5: {
                display();
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

}while (ch!=6);
}

