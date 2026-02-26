#include <stdio.h>
int power(int a,int b)
{
    if(b==1)
        return a;
    else
        return a*power(a,b-1);
}
int main()
{
    int x=4,y=2;
    int res=power(x,y);
    printf("\nx raised to power y is %d",res);
    return 0;
}
