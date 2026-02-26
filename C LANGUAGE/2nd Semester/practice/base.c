#include <stdio.h>
int main()
{
    int b,p,prod;
    printf("Enter base:");
    scanf("%d", &b);
    printf("Enter power:");
    scanf("%d", &p);

    while(p>0)
    { 
        prod=prod*b;
        p--;
    }
    printf("Result:%d\n",prod);
    return 0;
}
