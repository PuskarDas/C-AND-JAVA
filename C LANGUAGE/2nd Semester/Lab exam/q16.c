#include <stdio.h>
int prime(int a)
{
    int p=1;
    for(int i=2;i<=a/2;i++)
    {
        if(a%i==0)
            p=0;
    }
    return p;
}
void main()
{
    int n;
    printf("\nEnter size of array:");
    scanf("%d",&n);
    int arr[n];

    int *ptr=arr;
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter array elements:");
        scanf("%d",ptr+i);
    }
    
    printf("\nPrime array elements are:-\n");
    for(int i=0;i<n;i++)
    {
        if(prime(*(ptr+i)))
        {
            printf("%d, ",*(ptr+i));
        }
    }
}