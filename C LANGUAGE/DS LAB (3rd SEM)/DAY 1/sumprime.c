#include <stdio.h>
#include <stdlib.h>
int isPrime(int num) 
{
    if(num<=1)
        return 0;
    for(int i=2;i*i<=num;++i) 
    {
        if(num%i==0)
            return 0;
    }
    return 1;
}
int sumOfPrimes(int *arr,int n) 
{
    int sum=0;
    for(int i=0;i<n;++i) 
    {
        if(isPrime(arr[i]))
            sum+=arr[i];
    }
    return sum;
}
int main() 
{
    int n;
    int *arr;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));

    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;++i) 
        scanf("%d",&arr[i]);

    int sum=sumOfPrimes(arr,n);
    printf("Sum of prime elements: %d\n",sum);

    free(arr);
    return 0;
}