#include <stdio.h>
int main()
{
    int m,n;
    printf("Enter two integers\n:");
    scanf("%d %d",&m, &n);
     
    while(n>0)
    {
        int r=m%n;
        m=n;
        n=r;
    }
    printf("GCD = %d\n", m);
    return 0;
}
