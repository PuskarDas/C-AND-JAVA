//3-tuple conversion
#include<stdio.h>
int main()
{
    int n,i,j;
    
    printf("enter the  number of elements of the array:");
    scanf("%d",&n);
    int arr[n][n];
    printf("\n enter the elements of the array:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int count=0,zcount=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                count++;
            }
            else
            {
                zcount++;
            }
        }
    }
if(count<zcount)
{
    printf("the given matrix is a sparse matrix.\n");
}
printf("The number of non zero elements are%d",count);
int sm[count+1][3];
    sm[0][0] = n;     
    sm[0][1] = n;      
    sm[0][2] = count;  
    
    int k=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                sm[k][0] = i;     
                sm[k][1] = j;     
                sm[k][2] = arr[i][j]; 
                k++;
            }
        }
    }

    
    printf("\nSparse Matrix in 3-tuple format:\n");
    for(i=0;i<=count;i++)
    {
        printf("%d\t%d\t%d\n", sm[i][0], sm[i][1], sm[i][2]);
    }

    return 0;
}