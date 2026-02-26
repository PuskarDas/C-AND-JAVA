#include <stdio.h>
int prime(int a)
{
    int p=1;
    for(int i=2;i<=a/2;i++)
    {
        if(a%i==0)
            p=0;
    }
    return p;
}

void main()
{
    int x=0;
    for(int i=1;i<20;i++)
    {
        printf("\nEnter the number:");
        scanf("%d",&x);
        if(prime(x)==1)
            printf("\nPrime number");
    }
}