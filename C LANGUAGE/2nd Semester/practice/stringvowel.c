#include <string.h>
#include <stdio.h>
int main()
{
   char str[50];
   char vow[]="aeiouAEIOU";
   int v=0,l=0;
   char ch='a';
   printf("Enter the text:");
   gets(str);
   l=strlen(str);

   for(int i=0;i<l;i++)
   {
        ch=str[i];
        if(strchr(vow,ch)!=NULL)
        {
            v++;
        }   
   }
   printf("\nNo.of vowels is %d",v);
   return 0;
}