#include <stdio.h>
int main()
{
    int mat1[3][4],mat2[3][4],sum[3][4];
    printf("For 1st array:-")
    for(int i=0;i<3;i++)   
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("For 2nd array:-");    
    for(int i=0;i<3;i++)   
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&mat2[i][j]);
        }
    }
    for(int i=0;i<3;i++)   
    {
        for(int j=0;j<4;j++)
        {
            sum[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    printf("\nThe sum of arrays is:\n");
    for(int i=0;i<3;i++)    
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}

