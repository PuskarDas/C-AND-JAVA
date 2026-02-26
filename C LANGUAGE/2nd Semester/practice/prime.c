#include <stdio.h>
int main()
{
    int num,r=0;
    int a=2;
    printf("Enter a number:");
    scanf("%d",&num);

    do
    {
        if(num%a==0)
            r++;
        a++;
    } 
    while (a<num);

    if(num==1 || num==0)
        printf("It is neither prime nor composite");
    else if(r==0)
        printf("It is prime number");
    else
        printf("It is composite number");

    return 0;
}
