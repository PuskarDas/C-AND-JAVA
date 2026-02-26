#include<stdio.h>
#include<stdlib.h>
int n,*ptr;
void Reverse()
{
    for(int i=0;i<n/2;i++)
    {
        int temp;
        temp=ptr[i];
        ptr[i]=ptr[n-i-1];
        ptr[n-i-1]=temp;
    }
}
int main()
{
    printf("Enter the value of n: ");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the elements: ");
        scanf("%d",ptr[i]);
    }

    Reverse();
    printf("Reverse Content: ");
    for(int i=0;i<n;i++)
        printf("%d",ptr[i]);
    
    return 0;
}