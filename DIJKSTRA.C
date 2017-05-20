#include<stdio.h>
#include<conio.h>
void dij(int n,int v,int cost[10][10],int  dist[10])
{
    int i,u,count,w,flag[10],min;
    for(i=1;i<=n;i++)
        flag[i]=0,dist[i]=cost[v][i];
    count=2;
    while(count<=n)
    {
		min=999;
        for(w=1;w<=n;w++)
            if(dist[w]<min && !flag[w])
            min=dist[w],u=w;
        flag[u]=1;
        count++;
        for(w=1;w<=n;w++)
            if((dist[u]+cost[u][w]<dist[w])&& !flag[w])
                dist[w]=dist[u]+cost[u][w];
    }
}
void main()
{
    int n,v,i,j,cost[10][10],dist[10];
    clrscr();
    printf("n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        scanf("%d",&cost[i][j]);
        if(!cost[i][j])
            cost[i][j]=999;
    }
    printf("enter source:");
    scanf("%d",&v);
    dij(n,v,cost,dist);
    dist[v]=0;
    for(i=1;i<=n;i++)
			printf("%d->%d,cost=%d\n",v,i,dist[i]);
    getch();

}
