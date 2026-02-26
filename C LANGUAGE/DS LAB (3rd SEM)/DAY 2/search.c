#include <stdio.h>    
#include <stdlib.h>                                       
int search(int *arr,int n,int target)  
{
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)==target)
            return i;
    }
    return -1; 
}
int main()
{
    int n,target;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    int *arr=(int *)malloc(n*sizeof(int)); 

    printf("\nEnter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    printf("Enter the element to search: ");
    scanf("%d",&target);

    int index=search(arr,n,target);
    if(index!=1)
        printf("Element %d found at index %d",target,index);
    else
        printf("ELement %d not found ");
    return 0;
}