#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,*ptr;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    ptr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
    int smallest=*ptr;
    int largest=*ptr;
    for(int i=0;i<n;i++)
    {
        if(*(ptr+i)<smallest)
            smallest= *(ptr+i);
        else if(*(ptr+i)>largest)
            largest= *(ptr+i);
    }

    printf("\nSmallest element: %d",smallest);
    printf("\nLargest element: %d",largest);
    free(ptr);
    return 0;
}