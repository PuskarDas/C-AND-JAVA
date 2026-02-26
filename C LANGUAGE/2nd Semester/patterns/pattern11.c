#include <stdio.h>
int main()
{
    int x,i,sp;
    char j;
    printf("Enter no. of rows:");
    scanf("%d",&x);
    int a=65;

    for(i=1;i<=x;i++)
    {
        for(sp=1;sp<=x-i;sp++)
            printf(" ");
        for(j=65;j<=64+i;j++)
            printf("%c",j);
        printf("\n");
    }
    return 0;
}
