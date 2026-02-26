#include <stdio.h>
#include <stdlib.h>
struct CRICKET
{
    char name[100];
    int run;
}cri;
int main()
{
    int n;
    printf("Enter no.of cricketers:");
    scanf("%d",&n);

    struct CRICKET cr[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter cricketer name:");
        scanf("%s",&cr[i].name);
        printf("\nEnter Runs scored:");
        scanf("%d",&cr[i].run);
        printf("\n");
    }
    

    for(int i=0;i<n;i++)
    {
        if(cr[i].run>50)
        {
            printf("\nName:%s",cr[i].name);
            printf("\nRuns scored:%d",cr[i].run);
            printf("\n");
        }        
    }
    return 0;
}