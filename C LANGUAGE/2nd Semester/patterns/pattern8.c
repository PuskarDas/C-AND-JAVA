#include <stdio.h>
void main()
{
    int i,j,sp,k;
    
    for(i=5;i>=1;i--)
    {
        for(sp=1;sp<=(5-i);sp++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        for(k=i-1;k>=1;k--)
        {
            printf("%d",k);
        }
        printf("\n");
    }
}




