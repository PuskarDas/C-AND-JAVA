/*input 4*4 array and print the diagonal elements*/
#include <stdio.h>
void main()
{
    int a[4][3];

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
            if(i==j || i+j==3)
            {
                printf("%d\t",a[i][j]);
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }
}
