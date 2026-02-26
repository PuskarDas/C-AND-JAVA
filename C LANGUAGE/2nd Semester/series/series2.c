#include <stdio.h>
#include <math.h>
int main() 
{
    int n,i;
    long long int sum=0;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    printf("The series is:");
    
    for(i=1;i<=n;i++) 
    {
        sum+=pow(i,i);
        if(i>1) 
        {
            printf(" + ");
        }
        printf("%d^%d",i,i);
    }
    printf("= %lld",sum);
    return 0;
}
