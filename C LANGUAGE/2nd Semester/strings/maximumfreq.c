#include <string.h>
#include <stdio.h>
void main()
{
   char st[30],st1[30];
   int l=0,c,max;
   char ch='a',max_ch;
   printf("Enter the text:");
   gets(st);
   l=strlen(st);
   
   for(char ch1='a',ch2='A';ch1<='z';ch1++,ch2++)
   {
       c=0;
       for(int i=0;i<l;i++)
       {    
            if(st[i]==ch1 || st[i]==ch2)
                c++;
       }
       if(c>max)
       {
        max=c;
        max_ch=ch1;
       }
   }
   printf("\nCharacter with maximum frequency: %c with frequency %d",max_ch,max);
}

