#include <stdio.h>
#define max 20

int ht[max];
int m;

void insert(int key)
{
    int index=key % m;
    if (ht[index]==-1)
    {
        ht[index]=key;
    }
    else
    {
        int i=1;
        while (ht[(index+i)%m]!=-1)
        {
            i++;
        }
        ht[(index+i)%m]=key;
    }
}

void display()
{
    printf("\nhash table\n");
    for (int i=0;i<m;i++)
    {
        if (ht[i]!=-1)
        printf("address %d:%d \n",i,ht[i]);
        else
        printf("address %d:empty \n",i);
    }
}

int main()
{
    int n,key;
    printf("enter size of hash table(m):");
    scanf("%d",&m);
    printf("enter no. of employee records:");
    scanf("%d",&n);
    for (int i=0;i<m;i++)
    {
        ht[i]=-1;
    }
    printf("enter %d employee keys (4-digit):\n",n);
    for (int i =0;i<n;i++)
    {
        scanf("%d",&key);
        insert(key);
    }
    display();
    return 0;
}
