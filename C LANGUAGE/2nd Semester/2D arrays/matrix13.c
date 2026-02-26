/* 4x4 array and print rotation of elements by 180*/
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

    for(int i=0;i<4;i++)    /*Horizontal flip of elements*/
    {
        for(int j=0;j<2;j++)
        {
            c=a[i][j];
            a[i][j]=a[i][3-j];
            a[i][3-j]=c;        
        }
    }
   
    for(int j=0;j<4;j++)    /*Vertical flip of elements*/
    {
        for(int i=0;i<2;i++)
        {
            c=a[i][j];
            a[i][j]=a[3-i][j];
            a[3-i][j]=c;        
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
