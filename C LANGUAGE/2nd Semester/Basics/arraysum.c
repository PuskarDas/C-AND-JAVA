#include <stdio.h>
#include <conio.h>

void main()
{
    int a[10];
    int sum=0, avg=0;
    int i=0;

    for(i=0; i<10; i++)
    {
        printf("\n Enter array elements:");
        scanf("%d", &a[i]);
    }

    for(i=0; i<10; i++)
    {
        sum= sum+ a[i];
    }
    avg= sum/10;
    printf("\n sum= %d", sum);
    printf("\n average= %d", avg);

    getch();
}