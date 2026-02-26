/* 4x4 array and finding the saddle point */
#include <stdio.h>
void main()
{
    int big,small,r,c;
    int a[4][4],saddle=0;
    
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
        small=a[i][0];
        r=i;
        c=0;
        for(int j=0;j<4;j++)
        {
            if(a[i][j]<small)
            {
                small=a[i][j];
                r=i;
                c=j;
            }
        }
    }
    
    big=a[r][c];
    
    for(int i=0;i<4;i++)
    {
        if(a[i][c]>big)
        {
            big=a[i][c];
            r=i;
            saddle=1;
        }
    }

    if(saddle==0)
        printf("\nThe saddle point is (%d,%d) with value: %d\n",r,c,big);
    else
        printf("\nThere is no saddle point");
}
