#include <stdio.h>
int main()
{
    int i;
    char s1[]="Puskar  ";
    char s2[]=" Das";
    printf("Before adding:");
    puts(s2);
    printf("After adding:\n");

    for(i=0;i<5;i++)
    {
        s1[6+i]=s2[i];
    }
    puts(s1);
    return 0;
}

