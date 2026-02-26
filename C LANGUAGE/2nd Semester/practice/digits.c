#include <stdio.h>
int main() 
{
    int n,current,result=0;
    int digit,d=0;
    int arr[5], res[5];
    printf("Enter a number less than 65555: ");
    scanf("%d",&n);

    if(n>=65555 || n<0) 
    {
        printf("Invalid input, enter a number less than 65555\n");
    }
    printf("Enter the digit to delete:");
    scanf("%d",&digit);
    
    while(n>0) 
    {
        current=n%10;
        arr[d++]=current;
        n/=10;
    }

    for(int i=d-1;i>=0;i--) 
    {
        if(arr[i]!=digit) 
        {
            res[result++]=arr[i];
        }
    }

    printf("New number:");
    for(int i=0;i<result;i++) 
    {
        printf("%d",res[i]);
    }
    printf("\n");
    return 0;
}