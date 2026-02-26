#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char s1[50];
    printf("Enter the string:");
    gets(s1);
    int l=strlen(s1);

    for(i=0;i<l;i++)
    {
        if(isupper(s1[i]))
            s1[i]=tolower(s1[i]);
    }
    printf("\nThe string after converting is:%s",s1);
    return 0;
}

