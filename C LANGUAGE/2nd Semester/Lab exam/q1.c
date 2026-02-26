#include <stdio.h>
int main()
{
    int arr[100],n,big,sbig,diff;
    printf("\nEnter size of array:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    big=arr[0];
    if(arr[0]>arr[1])
    {
        sbig=arr[1];
        big=arr[0];
    }
    else
        big=arr[0];
        sbig=arr[1];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>big)
        {
            sbig=big;
            big=arr[i];
        }    
    }
diff=big-sbig;
printf("Absolute Difference:%d",diff);
return 0;
}