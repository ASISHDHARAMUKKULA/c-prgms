#include<stdio.h>
#include<conio.h>
int n,i,j,ad[10][10];
char ver[20];
void display()
{
    printf("\nVERTEX\tADJACENT VERTICES\n");
    printf("------------------------------------------------\n  ");
    for(i=0;i<n;i++)
        printf("%c ",ver[i]);
    printf("   ----\n");
    for(i=0;i<n;i++)
    {
        printf("%c|",ver[i]);
        for(j=0;j<n;j++)
        {
                printf("%d ",ad[i][j]);
        }
        printf("\n");
    }
}
int find(char v)
{
    int k;
    for(k=0;k<n;k++)
    {
        if(ver[k]==v)
            return k;
    }
    return -1;
}
void main()
{
    char s,d,v;
    int op;
    n=0;
    do
    {
        printf("\n---------------------OPERATIONS-----------------------\n");
        printf("[1].INSERT VERTEX\n[2].DELETE VERTEX\n[3].ADD AN EDGE\n[4].DELETE AN EDGE\n[5].FIND VERTEX\n[6].DISPLAY\n[0].EXIT");
        printf("\n\nChoose an Operation:");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("\nEnter Vertex:");
                    fflush(stdin);
                    scanf("%c",&v);
                    if(find(v)!=-1)
                        printf("\nVERTEX already exists");
                    else
                    {
                        ver[n++]=v;
                        printf("\nVERTEX INSERTED");
                    }
                    break;
            case 2: if(n==0) printf("\nGRAPH IS EMPTY");
                    else
                    {
                        i=n-1;
                        v=ver[n-1];
                        for(j=0;j<n;j++)
                        {
                            ver[i]=0;
                            ad[i][j]=ad[j][i]=0;
                        }
                        n--;
                        printf("\nVERTEX DELETED Is :%c",v);
                    }
                    break;
            case 3: if(n==0) printf("\nGRAPH IS EMPTY");
                    else
                    {
                        printf("\nEnter Source Vertex:");
                        fflush(stdin);
                        scanf("%c",&s);
                        printf("\nEnter Destination Vertex:");
                        fflush(stdin);
                        scanf("%c",&d);
                        if(s!=d && find(s)!=-1 && find(d)!=-1)
                        {
                            i=find(s);
                            j=find(d);
                            if(ad[i][j]==0)
                            {
                                ad[i][j]=1;
                                printf("\nEDGE INSERTED\n");
                            }
                            else
                                printf("\nAlready they are connected by an EDGE");
                        }
                        else
                            printf("\nEDGE Is Not Connected\n");
                    }
                    break;
            case 4: if(n==0)
                        printf("\nGRAPH IS EMPTY");
                    else
                    {
                        printf("\nEnter Source Vertex:");
                        fflush(stdin);
                        scanf("%c",&s);
                        printf("\nEnter Destination Vertex:");
                        fflush(stdin);
                        scanf("%c",&d);
                        i=find(s);
                        j=find(d);
                        if(ad[i][j]!=1)
                            printf("\nThere is No edge Connecting them");
                        else
                        {
                            ad[i][j]=0;
                            printf("\nEDGE DELETED\n");
                        }
                    }
                    break;
            case 5: if(n==0)
                        printf("\nGRAPH IS EMPTY");
                    else
                    {
                        printf("\nEnter Vertex:");
                        fflush(stdin);
                        scanf("%c",&v);
                        if(find(v)!=-1)
                            printf("\nVERTEX FOUND");
                        else
                        printf("\nVERTEX NOT FOUND");
                    }
                    break;
            case 6: if(n==0)
                        printf("\nGRAPH IS EMPTY");
                    else
                        display();
                    break;
        }
    }while(op!=0);
}
