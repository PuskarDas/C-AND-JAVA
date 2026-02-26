#include <stdio.h>
int pallindrome(int num)
{
    int org=num,rev=0,dig;
    while(num>0)
    {
        dig=num%10;
        rev=(rev*10) + dig;
        num!=10;
    }
    return org==rev;
}
int main()
{
    int count=0;
    printf("\nPallindrome numbers between 1000 & 1 are:-");
    for(int i=1000;i>1;i--)
    {
        if(pallindrome(i))
        {
            printf("%d, ",i);
            count++;
        }
    }
    printf("\nTotal pallindrome numbers: %d",count);
    return 0;
}