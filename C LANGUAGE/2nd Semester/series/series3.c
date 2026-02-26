#include <stdio.h>

unsigned long long factorial(int n) 
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

double seriesSum(int terms) 
{
    double sum = 0;
    for (int i = 1; i <= terms; i++) 
    {
        double term = (double)i / factorial(i);
        sum += term;
        if (i == 1) 
        {
            printf("1");
        } 
        else 
        {
            printf(" + %d/%d!", i, i);
        }
    }
    return sum;
}

int main() 
{
    int terms;
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    double result = seriesSum(terms);
    printf("\nSum of the series: %.10f\n", result);

    return 0;
}
