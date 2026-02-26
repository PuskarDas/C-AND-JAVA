#include <stdio.h>
void main()
{
    int n;
    char c='*'; 
    printf("Enter the no.of rows:");
    scanf("%d",&n);   
    int k=n*2-1;

    for(int i=1;i<=k;i++) 
    {
        for (int j=1;j<=k;j++) 
        {
            if(j==i || j==k-i+1) 
            {
                printf("%c",c);
            }
            printf(" ");
        }
        printf("\n");
    }
}
