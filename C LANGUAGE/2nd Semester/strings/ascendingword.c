#include <string.h>
#include <stdio.h>
void main()
{
   char st[30],word[30];
   int l=0,c;
   char ch='a',sp=' ';
   printf("Enter the text:");
   gets(st);
   strncat(st,&sp,1);
   l=strlen(st);
   
   printf("\nWords in ascending order of length:\n");
   for(int j=1;j<=l;j++)
   {
    for(int i=0;i<l;i++)
    {
     if(st[i]!=' ')
        strncat(word,&st[i],1);
     else
     {
        if(strlen(word)==j)
            printf("\n%s ",word);
        strcpy(word,"");
     }
    }
   }
}