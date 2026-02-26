#include <stdio.h>
#include <math.h>
void main()
{
    float a,b,sum;
    printf("Enter number of terms:");
    scanf("%f",&a);
    float fact=1;

    for(int i=1;i<=a;i++)
    {
        fact*=i;
        b=i;
        sum+=b/fact;
        printf("%d/%d! ",i,i);
        if(i<a)
        {
            printf("+");
        }
    }
    printf("\nThe sum of the series:%f", sum);
}
