#include <string.h>
#include <stdio.h>
void main()
{
   char st[100];
   char ch1='a',ch2='a';
   int w=0,l=0;
   printf("Enter the sentence:");
   gets(st);
   l=strlen(st);

   for(int i=0;i<l;i++)
   {
        ch1=st[i];
        ch2=st[i+1];
        if(ch1==' ' && ch2!=' ') 
            w++;   
   }
   printf("\nNo.of words is %d",w+1);
}

