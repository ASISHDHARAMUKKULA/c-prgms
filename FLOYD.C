#include<stdio.h>
#include<conio.h>
void main()
{
	int n,d[10][10],p[10][10],i,j,k;
	clrscr();
	printf("enter no.of nodes:");
	scanf("%d",&n);
	printf("enter graph matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				d[i][j]=0;
			else if(p[i][j]==0)
				d[i][j]=999;
			else
				d[i][j]=p[i][j];
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(d[i][j] > d[i][k] + d[k][j])
					d[i][j]=d[i][k]+d[k][j];

			}
		}
	}

	printf("path matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	getch();
}