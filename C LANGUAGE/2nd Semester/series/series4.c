#include <stdio.h>
int factorial(int n) 
{
    int fact = 1;
    for (int i = 1; i <= n; i++) 
    {
        fact *= i;
    }
    return fact;
}
int main() 
{
    int n;
    double sum = 0.0;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("The series is: ");
    for (int i = 1; i <= n; i++) 
    {
        double term = (i * i) / (double)factorial(i);
        sum += term;
        
        if (i == 1) 
        {
            printf("1");
        } 
        else 
        {
            printf(" + (%d^2/%d!)", i, i);
        }
    }
    printf("\nThe sum of the series is: %.5lf\n", sum);
    return 0;
}