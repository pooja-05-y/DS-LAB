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

//newNode=(struct node*)malloc(sizeof(struct node));
//printf("enter data");
//scanf("%d",& newnode->data);
//newnnode->next=0;
//if (head==0)
//{
//    head=temp=newnode;
//}
//else
//{
//    temp->next=newnode;
//    temp=newnode;
//}

void InsertAtBeginning(int data)
{
    struct node *newnode=(struct node*) malloc (sizeof (struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    printf("node inserted at the beginning");
}

void InsertAtAnyPosition(int data,int pos)
{
    int i;
    struct node *newnode,*temp=head;
    if (pos<1)
    {
        printf("invalid position");
        return;
    }
    if (pos==1)
    {
        InsertAtBeginning(data);
        return;
    }
    newnode=(struct node*)malloc(sizeof (struct node));
    newnode->data=data;
    for (i=1; i<pos-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("position out of range");
        free(newnode);
    }
    else{
        newnode->next=temp->next;
        temp->next=newnode;
        printf("node inserted at position %d\n",pos);
    }
}
    void InsertAtEnd(int data)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        if (head==NULL)
        {
            head=newnode;
        }
        else
        {
            struct node *temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        printf("node inserted at the end");
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
        int ch,n,data,pos;
        while (1)
        {
            printf("\n");
            printf("1.creation, 2.insert at beginning, 3. insert at any pos, 4.insert at end, 5.display");
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
                    printf("enter data");
                    scanf("%d",&data);
                    InsertAtBeginning(data);
                    break;
                }
            case 3:
                {
                    printf("enter data");
                    scanf("%d",&data);
                    printf("enter position");
                    scanf("%d",&pos);
                    InsertAtAnyPosition(data,pos);
                    break;
                }
            case 4:
                {
                    printf("enter data");
                    scanf("%d",&data);
                    InsertAtEnd(data);
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

