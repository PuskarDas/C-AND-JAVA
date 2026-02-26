#include <stdio.h> 
int check(int size, int chk[],int element,int *p)
{
    for(int i=0;i<size;i++)
    {
        if(chk[i]==element)
            return 1;
    }
    chk[*p]=element;
    *p++;
    return 0;
}
int main()
{
    int m,n;
    printf("Enter no.of rows:");
    scanf("%d",&m);
    printf("Enter no.of columns:");
    scanf("%d",&n);
    int arr[m][n],ch[m*n],pos=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter array elements: ");
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("\nThe array is:-\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c=0;
            for(int k=0;k<m;k++)
            {
                for(int l=0;l<n;l++)
                {
                    if(arr[i][j]==arr[k][l] && check(m*n,ch,arr[k][l],&pos)==0)
                        c++;
                } 
            }
            if(c>0)
                printf("\nFrequency of %d elements is %d",arr[i][j],c);
        }
    }
}