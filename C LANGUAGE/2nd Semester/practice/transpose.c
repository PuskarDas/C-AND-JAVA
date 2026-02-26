#include <stdio.h>
int main()
{
    int mat[3][3],c;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<3;i++)
    {
        for(int j=i;j<3;j++)
        {
            c=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=c;        
        }
    }
    printf("\nTranspose array is:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
