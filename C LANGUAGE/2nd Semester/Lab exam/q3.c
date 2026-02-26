#include <stdio.h>
#include <math.h>
int main()
{
    int arr[3][3],n;
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
            n=sqrt(arr[i][j]);
            if(arr[i][j]==(n*n))
                printf("\nThe perfect square elements are:%d",arr[i][j]);
        }
    }
    return 0;
}
