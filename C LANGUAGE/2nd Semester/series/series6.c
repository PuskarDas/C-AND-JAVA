#include <stdio.h>
int main()
{
    long a,fact,sum;
    printf("\nEnter the number of terms:");
    scanf("%ld",&a);

    for(int i=1;i<=a;i++)
    {
        int n=1;
        fact=1;
        while(n<=i)
        {
            fact*=n;
            n++;
        }
        sum+=fact;
    }
    printf("\nThe sum of series is: %ld",sum);
    return 0;
}
