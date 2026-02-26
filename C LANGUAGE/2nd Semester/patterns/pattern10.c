#include <stdio.h>
int main()
{
    int i,j,k,sp,x;
    printf("Enter number of rows:");
    scanf("%d",&x);                                                              
    
    for(i=1;i<=x;i++)
    {
        for(sp=1;sp<=(x-i);sp++)
            printf("  ");
        for(j=1;j<=(2*i-1);j+=2)
            printf("%d ",j);
        for(k=2*i-3;k>=1;k-=2)
            printf("%d ",k);
        printf("\n");
    }
    return 0;
}
