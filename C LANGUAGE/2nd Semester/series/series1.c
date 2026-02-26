#include <stdio.h>
int main()
{
    int n,i,sum;
    printf("Enter the number of terns:");
    scanf("%d",&n);

    for(i=1;i<=n;++i)
    {
        sum+=i*i;
        printf("%d^2", i);
        if(i<n)
        {
            printf(" + ");
        }
    }
    printf("= %d",sum);
    return 0;
}
