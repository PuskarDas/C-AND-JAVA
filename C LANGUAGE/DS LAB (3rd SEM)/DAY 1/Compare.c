#include <stdio.h>
void Compare(int *a,int *b) 
{
    if(*a>*b)
        printf("%d is greater than %d\n",*a,*b);
    else if(*a<*b)
        printf("%d is smaller than %d\n",*a,*b);
    else
        printf("%d and %d are equal\n",*a,*b);
}

int main() 
{
    int n1, n2;
    printf("Enter the first number: ");
    scanf("%d",&n1);

    printf("Enter the second number: ");
    scanf("%d",&n2);
    
    Compare(&n1,&n2);
    return 0;
}