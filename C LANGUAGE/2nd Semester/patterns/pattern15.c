#include <stdio.h>
void main()
{
    int sp,a,i,j,k;
    printf("Enter no.of rows:");
    scanf("%d",&a);

    for(i=1;i<=a;i++)
    {
        for(sp=1;sp<=(a-i);sp++)
            printf(" ");
        for(j=i;j>=1;j--)
            printf("*");
        for(k=2;k<=i;k++)
            printf("*");
        printf("\n");
    }
}
