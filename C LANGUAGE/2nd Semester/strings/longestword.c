#include <string.h>
#include <stdio.h>
void main()
{
   char st[30],word[30],maxw[30];
   int l=0,c;
   char ch='a',sp=' ';
   printf("Enter the text:");
   gets(st);
   strncat(st,&sp,1);
   l=strlen(st);

   for(int i=0;i<l;i++)
   {
    if(st[i]!=' ')
        strncat(word,&st[i],1);
    else
    {
        if(strlen(word)>strlen(maxw))
            strcpy(maxw,word);
        strcpy(word,"");
    }
   }
   printf("\nLongest word:%s",maxw);
}
