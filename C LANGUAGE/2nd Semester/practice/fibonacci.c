#include <stdio.h>
int main()
{
    int p1,p2;
    int i,n;
    printf("How many terms:");
    scanf("%d",&n);
    
    printf("Fibonacci series\n:");
    p2=0;
    p1=1;
    printf(" %d, %d, ", p2,p1);
    
    for(i=2;i<n;i++)
    {
        int term=p1+p2;
        printf("%d, ",term);
        p2=p1;
        p1=term;
    }
    return 0;
}

