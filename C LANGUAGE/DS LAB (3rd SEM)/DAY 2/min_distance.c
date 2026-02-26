#include<stdio.h> 
#include<stdlib.h>
#include<limits.h>                                                                
int minDistance(int arr[],int n,int x,int y) 
{
    int min_dist=INT_MAX;
    int prev=-1;
    for(int i=0;i<n;i++) 
    {
        if(arr[i]==x || arr[i]==y)
        {
            if(prev != -1 && arr[prev] != arr[i])
            {
                int dist=i-prev;
                if(dist<min_dist)
                    min_dist=dist;
            }
            prev=i;  //update last index
        }
    }
    return min_dist; 
}
int main() 
{
    int n,x,y;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));

    printf("Enter the elements of array: ");
    for (int i=0;i<n;i++) 
        scanf("%d",arr+i);

    printf("Enter the value of x: ");
    scanf("%d",&x);
    printf("Enter the value of y: ");
    scanf("%d",&y);

    int min_dist=minDistance(arr,n,x,y);
    printf("Minimum distance between %d and %d is %d\n",x,y,min_dist);

    free(arr);
    return 0;
}
