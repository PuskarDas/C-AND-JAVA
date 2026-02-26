#include <stdio.h>
#include <string.h>
int main()
{
    char s1[50],vow[]="aeiouAEIOU";
    int v=0,l;
    for(int i=1;i<=5;i++)
    {
        printf("\nEnter a name:");
        gets(s1);
        l=strlen(s1);
        
        v=0;
        for(int j=0;j<l;j++)
        {
            if(strchr(vow,s1[j])!=NULL)
                v++;
        }
        printf("\nNo.of vowels is:%d",v);
    }
    return 0;
}
