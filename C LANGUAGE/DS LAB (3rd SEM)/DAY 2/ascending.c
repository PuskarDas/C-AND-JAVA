#include<stdio.h> 
#include<stdlib.h> 
void swap(int *a,int *b)
{
    int temp=*a;                                                                  
    *a=*b;
    *b=temp;
}
void Sort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(*(arr+j)>*(arr+j+1))
                swap((arr+j),(arr+j+1));
        }
    }
}
void Print(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}

int main()
{
    int n,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    
    Sort(arr,n);
    printf("\nArry after sorting: ");
    Print(arr,n);

    free(arr);
    return 0;
}