#include<stdio.h>
#include<string.h>
struct Distance
{
    int km,m;
};
struct Distance Sum(struct Distance x,struct Distance y)
{
    struct Distance d;
    d.m = x.m + y.m;
    d.km = x.km + y.km;
    if(d.m>=1000)
    {
        d.km+=d.m/1000;
        d.m=d.m%1000;
    }
    return d;
}
int main()
{
    struct Distance d1,d2,sum;
    printf("Enter first distance: ");
    scanf("%d",&d1.m);
    printf("Enter second distance: ");
    scanf("%d",&d2.m);
    
    d1.km=d1.m/1000;
    d1.m=d1.m%1000;
    d2.km=d2.m/1000;
    d2.m=d2.m%1000;

    sum=Sum(d1,d2);
    printf("Summed distance:-\n %dkm and %dm",sum.km,sum.m);
    return 0;

}