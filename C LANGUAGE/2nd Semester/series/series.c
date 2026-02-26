#include <stdio.h>
int main()
{
    int n;
    int series=0;
    printf("Enter no.of terms:");
    scanf("%d",&n);
    
    printf("The series is:");
    for(int i=0;i<n;i++)
    {
        printf("%d, ",series);
        series=series*2+1;      
    }
    return 0;
}

