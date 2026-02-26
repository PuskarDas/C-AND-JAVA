#include <stdio.h>
#include <math.h>
int main() 
{

    int num,org,rem,r;
    printf("Armstrong numbers between 100 and 1000 are:\n");

    for(num=100;num<=1000;num++) 
    {
        org=num;
        r=0;

        while(org!=0) 
        {
            rem=org%10;
            r+=pow(rem,3);
            org/=10;
        }
        if(r==num) 
        {
            printf("%d\n",num);
        }
    }
    return 0;
}
