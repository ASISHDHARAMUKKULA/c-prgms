/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    
    int fact=1,num;
    if(argc!=2)
    {
        printf("Invalid usage");
    }
    num=atoi(argv[1]);
    if(num<0)
    {
        printf("enter valid argument");
        
    }
    while(num>=1)
    {
        fact=fact*num;
        num--;
    }
    printf("%d",fact);
}

