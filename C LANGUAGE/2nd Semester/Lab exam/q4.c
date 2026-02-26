#include <stdio.h>
int main()
{
    int arr[100],n,small,ssmall,diff;
    printf("\nEnter size of array:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    small=arr[0];
    if(arr[0]<arr[1])
    {
        ssmall=arr[1];
        small=arr[0];
    }
    else
        small=arr[0];
        ssmall=arr[1];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<small)
        {
            ssmall=small;
            small=arr[i];
        }    
    }
diff=small-ssmall;
printf("Absolute Difference:%d",diff);
return 0;
}