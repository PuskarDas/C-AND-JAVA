#include <string.h>
int main()
{
   char s1[20];
   int i,l=0;
   printf("Enter a string:");
   gets(s1);

   for(i=0;i<s1[i]!='\0';i++)
    {
        if(s1[i]!='\n')
            l++;
    }
    printf("The length of string is:%d",l);
    return 0;
}
