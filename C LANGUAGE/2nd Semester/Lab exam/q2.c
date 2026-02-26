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
int main()
{
    int arr[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(prime(arr[i][j])==1)
                printf("\nThe prime elements are:%d",arr[i][j]);
        }
    }
    return 0;
}
