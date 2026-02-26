/* 4x4 array and sum of two arrays */
#include <stdio.h>
void main()
{
    int a[4][4],b[4][4],dif[4][4];
    
    for(int i=0;i<4;i++)   /*input first array*/
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe array is:\n");

    for(int i=0;i<4;i++)    /*display first array*/
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<4;i++)   /*input second array*/
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&b[i][j]);
        }
    }
    printf("\nThe array is:\n");

    for(int i=0;i<4;i++)    /*display second array*/
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<4;i++)   /*difference of both arrays*/
    {
        for(int j=0;j<4;j++)
        {
            dif[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("\nThe difference of arrays is:\n");

    for(int i=0;i<4;i++)  /*display difference of arrays*/  
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",dif[i][j]);
        }
        printf("\n");
    }
}

