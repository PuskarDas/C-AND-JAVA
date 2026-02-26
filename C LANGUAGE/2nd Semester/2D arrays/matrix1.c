/* enter 4x4 array and display array elements*/
#include <stdio.h>
void main()
{
    int a[4][3];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe array is:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
