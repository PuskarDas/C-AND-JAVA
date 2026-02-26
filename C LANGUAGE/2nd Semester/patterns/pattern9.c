#include <stdio.h>
int main()
{
    int a,num=0;
    printf("Enter the number of rows:");
    scanf("%d",&a);

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(num==0)
            {
                printf("1");
                num=1;
            }
            else
            {
                printf("0");
                num=0;
            }
        }
         printf("\n");
    }
    return 0; 
}
