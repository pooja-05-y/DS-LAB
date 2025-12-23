#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void create(int n)
{
    struct node *newnode,*temp;
    int data,i;
    if (n<=0)
    {
        printf("no. of nodes should be >0");
        return;
    }
    for (i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if (newnode==NULL)
        {
            printf("memory allocation failed");
            return;
        }
        printf("enter data");
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        if (head==NULL)
        {
            head=newnode;
        }
        else
        {
            temp->next=newnode;
        }
        temp=newnode;
    }
    printf("linked list created");
}

void DeleteFirst()
{
    struct node *temp;
    if (head==NULL)
    {
        printf("linked list is empty");
        return;
    }
    temp=head;
    head=head->next;
    printf("deleted element=%d",temp->data);
    free(temp);
}

void DeleteLast()
{
    struct node *temp,*prev;
    if (head==NULL)
    {
        printf("linked list is empty");
        return;
    }
    if (head->next==NULL)
    {
        printf("deleted element=%d",head->data);
        free(head);
        head=NULL;
        return;
    }
    temp=head;
    while (temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    printf("deleted element=%d",temp->data);
    prev->next=NULL;
    free(temp);
}

void DeleteAtSpecificPos(int value)
{
    struct node *temp=head,*prev=NULL;
    if (head==NULL)
    {
        printf("linked list is empty");
        return;
    }
    if (head->data==value)
    {
        head=head->next;
        printf("deleted element=%d",temp->data);
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data!=value)
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("element not found");
        return;
    }
    prev->next=temp->next;
    printf("deleted element=%d",temp->data);
    free(temp);
}

void display()
{
    struct node *temp=head;
    if (head==NULL)
    {
        printf("list is empty");
        return;
    }
    printf("linked list =");
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main()
{
    int ch,n,data,pos,value;
    while (1)
    {
        printf("\n");
        printf("1.creation, 2.delete from the beginning, 3. delete from any pos, 4.delete from the end, 5.display");
        printf("\n enter your choice\n ");
        printf("\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("enter no of nodes");
                scanf("%d",&n);
                create(n);
                break;
            }
        case 2:
            {
                DeleteFirst();
                break;
            }
        case 3:
            {
                printf("enter value to be deleted");
                scanf("%d",&value);
                DeleteAtSpecificPos(value);
                break;
            }
        case 4:
            {
                DeleteLast();
                break;
            }
        case 5:
            {
                display();
                break;
            }
        default:
            {
                printf("invalid choice");
                break;
            }
        }
    }
    return 0;
}


