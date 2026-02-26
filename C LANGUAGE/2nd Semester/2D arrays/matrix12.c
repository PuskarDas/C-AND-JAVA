/* 4*4 array and print rotation of elements by 270*/
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

    for(int i=0;i<4;i++)   /*Transpose of elements*/
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<4;i++)   /*Vertical flip of elements*/
    {
        for(int j=i;j<4;j++)
        {
            c=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=c;        
        }
    }
    
    for(int j=0;j<4;j++)
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
