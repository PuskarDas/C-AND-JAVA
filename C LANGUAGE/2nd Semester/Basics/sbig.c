#include <stdio.h>
#include <conio.h>
void main()
{
    int i=0,a=0,big=0,sbig=0;
    printf("\nEnter first number:");
    scanf("%d",&big);
    printf("\nEnter second number:");
    scanf("%d",&sbig);

    for(i=1;i<=8;i++)
    {
        printf("\nEnter next number:");
        scanf("%d",&a);
        if(a>big)
        {
            sbig=big;
            big=a;
        }
        if(a>sbig && a<big)
        {
            sbig=a;
        }
    }
    printf("\nBiggest number:%d",big);
    printf("\nSecond biggest number:%d",sbig);
    getch();

}