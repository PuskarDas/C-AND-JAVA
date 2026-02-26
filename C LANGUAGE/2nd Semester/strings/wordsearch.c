#include <string.h>
#include <stdio.h>
void main()
{
   char st[30],word1[30],word2[30];
   int l=0,found=0;
   char ch='a',sp=' ';
   printf("Enter the text:");
   gets(st);
   strncat(st,&sp,1);
   l=strlen(st);
   printf("\nEnter the word to search:");
   gets(word1);

   for(int i=0;i<l;i++)
   {
    if(st[i]!=' ')
        strncat(word2,&st[i],1);
    else
    {
        if(strcmp(word1,word2)==0)
        {
            printf("\nWord found at:%d",i);
            found=1;
        }
        strcpy(word2,"");
    }
   }
   if(found==0)
    printf("\nWord not found");
}
