#include <stdio.h>
#include <stdlib.h>
void Find(int *A,int size,int *start,int *end)
{
    *start=(-1);
    *end=(-1);
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum=A[i];
        for(int j=i+1;j<size;j++)
        {
            sum+=A[j];
            if(sum==0)
            {
                *start=i;
                *end=j;
                return;
            }
        }
    }
}
int main()
{
    int n,s=0,e=0;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
 
    for(int i=0;i<n;i++)
    {
        printf("\nEnter array elements: ");
        scanf("%d",&ptr[i]);
    }
    
    Find(ptr,n,&s,&e);

    if(s>=0 && e>s)
    {
        printf("\nThe subsequence is: ");
        for(int i=s;i<=e;i++)
            printf("%d  ",ptr[i]);
    }
    else
        printf("\nNo subsequence found !!");
}