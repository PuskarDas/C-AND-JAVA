#include <stdio.h>
#include <string.h>
int main()
{
    char s1[50],vow[]="aeiouAEIOU";
    for(int i=1;i<=5;i++)
    {
        printf("\nEnter a name:");
        gets(s1);
        
        if(strchr(vow,s1[0])!=NULL)
            printf("\nIt does not start with consonant");
        else    
            printf("\nIt starts with consonant");
    }
    return 0;
}
