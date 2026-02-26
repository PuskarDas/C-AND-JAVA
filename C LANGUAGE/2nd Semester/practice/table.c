#include <stdio.h>
int main()
{
    int num,i;
    int arr[10];
    printf("Enter the number:");
    scanf("%d",&num);

    for(i=0;i<10;i++)
    {
        arr[i]=num*(i+1);
    }
    printf("\nMultiplication table of %d:-\n",num);

    for(i=0;i<10;i++)
    {
        printf("\n%d x %d= arr[%d]",num,(i+1),i);
    }
    return 0;
}
