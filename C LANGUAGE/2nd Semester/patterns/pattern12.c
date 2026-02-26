#include <stdio.h>
int main()
{
    int x,i,sp1,sp2,sp3,sp4;
    printf("Enter no. of rows:");
    scanf("%d",&x);

    for(i=1;i<=x;i++)
    {
        for(sp1=1;sp1<=i-1;sp1++)
            printf(" ");
        printf("*");
        for(sp2=1;sp2<=7-2*i;sp2++)
            printf(" ");
        printf("*");
        printf("\n");
    }
    for (i=1;i<=x;i++)
    {
       for(sp3=i-1;sp3>=1;sp3--)
            printf(" ");
        printf("*");
        for(sp4=7-2*i;sp4>=1;sp4--)
            printf(" ");
        printf("*");
        printf("\n");
    }
    return 0;
}