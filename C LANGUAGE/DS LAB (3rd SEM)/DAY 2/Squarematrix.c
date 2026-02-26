#include<stdio.h> 
#include<stdlib.h>                                                                  
void Count(int **A,int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]>0)
                c++;
        }
    }
    printf("\nNumber of non-zero elements: %d",c);
}
void LeadingSum(int **A,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
                sum+=A[i][j];
        }
    }
    printf("\nSum of the elements above the leading diagonal: %d",sum);
}
void Minor(int **A,int n)
{
    printf("\nElements below the minor diagonal: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i+j)>n-1)
                printf("%d ",A[i][j]);
        }
    }
}
void LeadingProduct(int **A,int n)
{
    int prod=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
               prod*=A[i][j];
        }
    }
    printf("\nProduct of the leading diagonal elements: %d",prod);
}

int main()
{
    int n=0;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    int **arr=(int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
        arr[i]=(int *)malloc(sizeof(int)*n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    Count(arr,n);
    LeadingSum(arr,n);
    Minor(arr,n);
    LeadingProduct(arr,n);
    return 0;
}