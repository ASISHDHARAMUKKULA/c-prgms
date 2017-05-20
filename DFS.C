#include<stdio.h>
#include<conio.h>
void dfs(int v);
int n,a[10][10];
int visited[10],orig[10]={0},s,d;
void path(int);
void main()
{
	int i,j,v;
	clrscr();
    printf("Enter the no. of nodes in the graph\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
	printf("Enter the source,desti:\n");
	scanf("%d%d",&s,&d);
	orig[s]=0;
    for(i=1;i<=n;i++)
		visited[ i]=0;
	printf("DFS:\nnode orig\n");
	dfs(s);
	printf("\npath b/w %d %d is:\n%d ",s,d,s);
	path(d);
    getch();
}
void dfs(int s)
{
    int i,stack[10],top=-1,pop;
    top++;
	stack[top]=s;
    while(top>=0)
    {
        pop=stack[top];
        top--;
        if(visited[pop]==0)
        {
			printf("%d    %d\n",pop,orig[pop]);
            visited[pop]=1;
        }
        else
            continue;
        for(i=n;i>=1;i--)
        {
            if(a[pop][i]==1 && visited[i]==0)
            {
                top++;
				stack[top]=i;
				if(orig[i]==0)
					orig[i]=pop;
            }
        }
    }
}
void path(int t)
{
	if(orig[t]==0 || t==s )
		return;
	else
	{
		path(orig[t]);
		printf(" %d ",t);
	}
}