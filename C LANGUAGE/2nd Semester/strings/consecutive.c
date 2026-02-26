#include <string.h>
#include <stdio.h>
void main()
{
   char st[30],st1[30];
   int l=0,c=0;
   char ch='a';
   printf("Enter the text:");
   gets(st);
   l=strlen(st);

   for(int i=0;i<l-1;i++)
        if(st[i]==st[i+1])
            c++;
    printf("\nFrequency of consecutive repeated letters:%d",c);
}
