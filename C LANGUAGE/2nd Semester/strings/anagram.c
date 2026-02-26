#include <stdio.h>
#include <string.h>
int main()
{
    char s1[50],s2[50];
    int l1,l2,found=0;
    printf("Enter first string:");
    gets(s1);
    printf("Enter second string:");
    gets(s2);
    l1=strlen(s1);
    l2=strlen(s2);
    
    if(l1!=l2)
        printf("\nIt is not an anagram");
    else
    {
        for(int i=0;s1[i]!='\0';i++)
        {
            found=1;
            for(int j=0;s2[j]!='\0';j++)
            {
                if(s1[i]==s2[j])
                {
                    s2[j]=' ';
                    found=0;
                    break;
                }
            }
            if(found==1)
                break;
        }
        if(found==0)
            printf("\nIt is an anagram");
        else
            printf("\nIt is not an anagram");
    }
    return 0;
}