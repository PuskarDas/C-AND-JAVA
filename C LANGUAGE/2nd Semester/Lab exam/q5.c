/*#include <string.h>
#include <stdio.h>
void main()
{
   char st[100];
   int st1[256]={0};
   printf("Enter the text:");
   fgets(st ,sizeof(st) ,stdin);
   
   for(int i=0;st[i]!='\0';i++)
   {
        st1[(unsigned char)st[i]]++;
   }
   printf("\nCharacter frequencies:-\n");
   for(int i=0;i<256;i++)
   {
    if(st1[i]>0 && i!='\n')
        printf("'%c' -> %d\n", i, st1[i]);
   }
}*/

#include <stdio.h>
#include <string.h>
int main()
{
     char st1[100],freq[100];
     
     printf("Enter the text:");
     gets(st1);
     int l=strlen(st1);

     for(char c1='A',c2='a';c1<='Z';c1++,c2++)
     {
          int c=0;
          for(int i=0;i<l;i++)
          {
               if (st1[i]==c1 || st1[i]==c2)
               {
                    c++;
               }
          }
          if(c>0)
               printf("\nFrequency of %c: %d",c2,c);
     }
}

