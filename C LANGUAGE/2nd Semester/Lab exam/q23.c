#include <stdio.h>
#include <math.h>
int perfect(int num)
{
    int t=(int)sqrt(num);
    if(t*t==num)
        return 1;
    else 
        return 0;
}
int main()
{
    printf("\nThe perfect square numbers between 1 to 90 is:- ");
    for(int i=1;i<=90;i++)
    {
        if(perfect(i)==1)
        {
            printf("%d, ",i);
        }
    }
    return 0;
}