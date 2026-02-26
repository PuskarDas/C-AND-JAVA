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
   
   printf("\nWords in descending order of length:\n");
   for(int j=l;j>=1;j--)
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
