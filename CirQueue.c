#include <stdio.h>
#include <ctype.h>
#define N 5
int queue[N];
int f=-1;
int r=-1;

void enqueue(int x)
{
    if(f==-1 && r==-1)
    {
        f=r=0;
        queue[r]=x;
    }
    else if ((r+1)%N==f)
    {
        printf("stack overflow");
    }
    else
    {
        r=(r+1)%N;
        queue[r]=x;
    }
}

void dequeue()
{
    if(f==-1 && r==-1)
    {
        printf("queue underflow");
    }
    else if (f==r)
    {
        printf("deleted element=%d",queue[f]);
        f=r=-1;
    }
    else
    {
        printf("deleted element=%d",queue[f]);
        f=(f+1)%N;
    }
}

void display()
{
    if (f==-1 && r==-1)
    {
        printf("stack is empty");
    }
    else
    {
        int i=f;
        while (1)
        {
            printf("%d",queue[i]);
            printf("\n");
            if (i==r)
            {
                break;
            }
            i=(i+1)%N;
        }
    }
}

void main()
{
        int ch=1,x;
        printf("1.enqueue, 2.dequeue, 3.display, 0.exit");
        printf("\n");
        while (ch!=0)
        {
            printf("\n");
            printf("enter your choice");
            scanf("%d",&ch);
            printf("\n");
            switch(ch)
            {
                case 1:
                {
                    printf("enter element");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
                }
                case 2:
                {
                     dequeue();
                    break;
                }
                case 3:
                {
                    display();
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    printf("invalid choice");
                    break;
                }
            }
        }
}
