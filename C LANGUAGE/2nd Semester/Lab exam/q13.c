#include <stdio.h>
int add(int *a, int *b, int *sum) 
{
    *sum=*a+*b;
    return sum;
}
int subtract(int *a, int *b, int *diff) 
{
    *diff=*a-*b;
    return diff;
}
int main() 
{
    int n1,n2,sum,diff;
    printf("Enter the first number:");
    scanf("%d",&n1);
    printf("Enter the second number:");
    scanf("%d",&n2);

    add(&n1,&n2,&sum);
    subtract(&n1,&n2,&diff);
    printf("\nAddition Result:%d",sum);
    printf("\nSubtraction Result:%d",diff);
    return 0;
}