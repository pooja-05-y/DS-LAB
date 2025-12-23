#include <stdio.h>
#define max 10
int visited[max];
int adj[max][max];
int n;

void DFS(int v)
{
    visited[v]=1;
    printf("%d",v);
    for(int i=0;i<n;i++)
    {
        if (adj[v][i]==1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    printf("enter no of vertices");
    scanf("%d",&n);
    printf("enter adjacency matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    for (int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("DFS traversal starting from vertex 0\n");
    DFS(0);
    return 0;
}