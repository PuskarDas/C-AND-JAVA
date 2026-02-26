#include <stdio.h>
void main()
{
    int m,n,c;
    printf("\nEnter no.of rows: ");
    scanf("%d",&m);
    printf("\nEnter no.of columns: ");
    scanf("%d",&n);

    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe array is:\n");

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<m;i++)
    {
        for(int j=i;j<n;j++)
        {
            c=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=c;        
        }
    }
    printf("\nTransposed array is:\n");

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
