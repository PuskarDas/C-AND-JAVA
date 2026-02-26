#include <stdio.h>
#include <math.h>
#define PI 3.1415927
int main()
{
    float d1,d2;
    float l,c,d;
    float l1,l2,l3;
    printf("\nEnter diammeters of pulleys(in m):");
    scanf("%f %f",&d1, &d2);
    printf("\nEnter distance between pulleys(in m):");
    scanf("%f",&c);

    d=d1-d2;
    l1=sqrt(4.0*c*c-d*d);
    l2=PI*(d1+d2)/2.0;
    l3=d*asin(d/(2.0*c));
    l=l1+l2+l3;

    printf("\nBelt length is %6.2fm",l);
    return 0;
}

