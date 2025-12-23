
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL;

void create(int n)
{
    struct node *newnode, *item, *temp, *prev;
    int data,i;
    if (n<0)
    {
        printf("n should be >0");
        return;
    }
    for (i=1;i<=n;i++)
    {
        newnode=(struct node*) malloc(sizeof(struct node));
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
            newnode->prev=NULL;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
        }
        temp=newnode;
    }
}

void InsertBeginning(int item)
{
    struct node *ptr=(struct node*) malloc(sizeof(struct node));
    if (head==NULL)
    {
        ptr->next=NULL;
        ptr->prev=NULL;
        ptr->data=item;
        head=ptr;
    }
    else
    {
        ptr->data=item;
        ptr->prev=NULL;
        ptr->next=head;
        head=ptr;
    }
}

void InsertLeft(int pos, int item)
{
    struct node *ptr=(struct node*) malloc(sizeof(struct node));
    struct node *temp, *prev;
    int i;
    printf("enter pos");
    scanf("%d",&pos);
    if (pos==1)
    {
        InsertAtBeginning(item);
    }
    pos=pos-1;
    temp=head;
    for(i=0;i<pos;i++)
    {
        temp=temp->next;
        if (temp==NULL)
        {
            printf("cannot insert data");
            return;
        }
    }
    ptr->data=item;
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next=ptr;
    temp->next->prev=ptr;
}

void DeleteSpecific()
{
    struct node *ptr, *temp;
    int val;
    printf("enter value");
    scanf("%d",&val);
    temp=head;
    while(temp->data!=val)
    {
        temp=temp->next;
    }
    if (temp->next==NULL)
    {
        printf("can't delete");
    }
    else if(temp->next->next==NULL)
    {
        temp->next=NULL;
        printf("node deleted");
    }
    else
    {
        ptr=temp->next;
        temp->next=ptr->next;
        ptr->next->prev=temp;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    if (head==NULL)
    {
        printf("empty");
    }
    else
    {
        ptr=head;
        while (ptr!=NULL)
        {
            printf("deleted %d",ptr->data);
            ptr=ptr->next;
        }
    }
}


int main()
{
    int ch,data,pos;
    printf("1.creation 2.Insert at beginning, 3.Insert to the left on a node, 4.delete based on specific value, 5.display");
    printf("enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            printf("enter no of nodes");
            scanf("d",&ch);
            create(ch);
            break;
        }
        case 2:
        {
            printf("enter data");
            scanf("%d",&data);
            InsertAtBeginning(data);
            break;
        }
        case 3:
        {
            printf("enter data");
            scanf("%d",&data);
            printf("enter pos");
            scanf("%d",&pos);
            InsertLeft(pos,data);
            break;
        }
        case 4:
        {
            DeleteSpecific();
            break;
        }
        case 5:
        {
            display();
            break;
        }
        case 6:
        {
            printf("exiting");
            break;
        }
        default:
        {
            printf("invalid choice");
            break;
        }
    }
}
