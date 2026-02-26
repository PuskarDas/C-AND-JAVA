#include <string.h>
#include <stdio.h>
void main()
{
   char st[30],st1[30];
   int v=0,l=0;
   char ch='a';
   printf("Enter the text:");
   gets(st);
   l=strlen(st);

   for(int i=0;i<l;i++)
        st1[l-i-1]=st[i];
    if(strcmp(st,st1)==0)
        printf("\nPallindrome word");
    else
        printf("\nNot pallindrome word");
}

