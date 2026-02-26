#include <stdio.h>
int main() 
{
    int as,ms=0,rs;
    printf("\nEnter the annual salary:");
    scanf("%d",&as);
    rs=as;

    while(rs>=12)
    {
        rs-=12;
        ms++;
    }
    printf("\nThe salary is %d per month",ms);
    return 0;
}

