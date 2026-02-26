#include <string.h>
#include <stdio.h>
void main()
{
   char st[100];
   char vowel[]="aeiouAEIOU";
   int v=0,l=0;
   char ch='a';
   printf("Enter the text:");
   gets(st);
   l=strlen(st);

   for(int i=0;i<l;i++)
   {
        ch=st[i];
        if(strchr(vowel,ch)!=NULL)
        {
            v++;
        }   
   }
   printf("\nNo.of vowels is %d",v);
}