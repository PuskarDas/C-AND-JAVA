#include <stdio.h>
int main()
{
    int num,i;
    printf("Enter a natural number:");
    scanf("%d",&num);
    i=num;
    
    do
    {
       printf("%d, ",i);
       i--; 
    } 
    while (i>0);
    return 0;
}
