#include <stdio.h>
/*int factorial(int num) 
{
    int fact = 1;
    for (int i = 1; i <= num; i++) 
    {
        fact *= i;
    }
    return fact;
}*/
int Fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*Fact(n-1);
}
int main() 
{
    int n=0;
    double sum=0.0;   
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("The series is: ");
    for (int i=1;i<=n;i++) 
    {
        double t=(i*i)/(double)Fact(i);
        sum+=t;        
        if(i==1) 
            printf("1");
        else 
            printf(" + (%d^2/%d!)",i,i);
    }
    printf("\nThe sum of the series: %.2lf",sum);
    return 0;
}