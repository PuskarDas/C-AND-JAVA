/*1 3 7 15 31 ...*/
#include <stdio.h>
void main()
{
    int a,i,b;
    printf("Enter no. of terms:");
    scanf("%d",&a);

    for(i=1;i<=a;i++)
    {
        b=2*b+1;
        printf("%d, ",b);
    }
}

