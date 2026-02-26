#include <stdio.h>
void main()
{
    int sp,a,i,j,k;
    printf("Enter no.of rows:");
    scanf("%d",&a);

    for(i=a;i>=1;i--)
    {
        for(j=1;j<=i;j++)
            printf("%d",j);
        for(sp=2*(a-i)-1;sp>=1;sp--)
            printf(" ");
        for(k=i;k>=1;k--)
        {
            if(k<a)
                printf("%d",k);
        }
        printf("\n");
    }
}
