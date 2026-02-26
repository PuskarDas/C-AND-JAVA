#include <string.h>
#include <stdio.h>
void main()
{
   char st[100];
   int v=0,l=0;
   char ch='a',ch1='a',ch2='a';
   printf("Enter the text:");
   gets(st);
   l=strlen(st);

   printf("\nCharacter in alphabetical order:\n");
   
   for(ch1='a',ch2='A'; ch1<='z'; ch1++,ch2++)
   {
        for(int i=0;i<l;i++)
        {
            ch=st[i];
            if(ch==ch1 || ch==ch2)
                printf("\n%c",ch);      
        }
   }
}
