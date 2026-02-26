#include <stdio.h>
#include <stdlib.h>
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
   int x=0,y=0,z;
   printf("Enter first number:");
   scanf("%d",&x);
   printf("Enter second number:");
   scanf("%d",&y); 
   if(prime(x)==1 && prime(y)==1 && abs(x-y)==2)
    printf("\nTwin Prime number");
   else
    printf("\nnot Twin prime number");
}

