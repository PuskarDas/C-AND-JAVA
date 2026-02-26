#include <stdio.h>
int main()
{
    int p;
    printf("Enter payment to be made:");
    scanf("%d",&p);
    
    printf("Enter currency note values:");
    int value,sum=0;
    
    while(sum<p)
    {
        scanf("%d", &value);
        printf("notes:%d\n", value);
        sum+=value;
    }
    printf("Amount payable: %d \nAmount paid:%d\n", p, sum);
    return 0;
}
