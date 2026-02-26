#include <stdio.h>
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int x=20,y=15;
    int res=gcd(x,y);
    printf("\nGCD of x & y is %d",res);
    return 0;
}

