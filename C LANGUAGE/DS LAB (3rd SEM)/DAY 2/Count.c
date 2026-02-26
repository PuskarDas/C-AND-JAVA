#include<stdio.h> 
#include<stdlib.h>
int Count(int *arr,int n,int a,int b) 
{
    int count=0; 
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)>=a && *(arr+i)<=b)
            count++;
    }
    return count;
}
void Print(int *arr,int n,int a,int b)
{
    int count=0;
    printf("\nThe numbers are: ");
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)>=a && *(arr+i)<=b)
            printf("%d, ",*(arr+i));
    }
}
int main()
{
    int n,a,b,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    int *arr=(int *)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    printf("\nEnter the value of a: ");
    scanf("%d",&a);
    printf("\nEnter the value of b: ");
    scanf("%d",&b); 
    if(a>b)
    {
        printf("Invalid range");
        return 1;
    }
    int c=Count(arr,n,a,b);
    if(c>0)
        printf("\nNumber of elements: %d",c);
    else
        printf("\nNo elements found !");
    
    Print(arr,n,a,b);
    return 0;
}
