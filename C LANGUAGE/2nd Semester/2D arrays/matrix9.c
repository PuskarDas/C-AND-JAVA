/* 4*4 array and print horizontal flip of elements*/
#include <stdio.h>
void main()
{
    int a[4][4],c;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe array is:\n");

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            c=a[i][j];
            a[i][j]=a[i][3-j];
            a[i][3-j]=c;        
        }
    }
    printf("\nFlipped array is:\n");

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
