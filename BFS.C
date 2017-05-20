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
    for(i=1;i<=n;i++)
        visited[i]=0;
	printf("BFS:\n");
	dfs(s);
	printf("\npath between %d and %d is:\n%d",s,d,s);
	path(d);
	getch();

}
void dfs(int v)
{
	int i,q[10],front=-1,rear=0,count=0,pop;
	front++;count++;
	q[front]=v;
	while(count!=0)
    {
		pop=q[front];
		front++;
		count--;
        if(visited[pop]==0)
        {
			printf("%d ",pop);
            visited[pop]=1;
        }
        else
            continue;
		for(i=0;i<=n;i++)
        {
            if(a[pop][i]==1 && visited[i]==0)
            {
				rear++;count++;
				q[rear]=i;
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
}
