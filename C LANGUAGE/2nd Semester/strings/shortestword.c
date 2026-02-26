#include <string.h>
#include <stdio.h>
void main()
{
   char st[30],word[30],minw[30];
   int l=0,c;
   char ch='a',sp=' ';
   printf("Enter the text:");
   gets(st);
   strncat(st,&sp,1);
   l=strlen(st);
   strcpy(minw,st);
   
   for(int i=0;i<l;i++)
   {
    if(st[i]!=' ')
        strncat(word,&st[i],1);
    else
    {
        if(strlen(word)<strlen(minw))
            strcpy(minw,word);
        strcpy(word,"");
    }
   }
   printf("\nShortest word:%s",minw);
}
