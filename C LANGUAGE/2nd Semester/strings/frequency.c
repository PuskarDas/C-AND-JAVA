#include <string.h>
#include <stdio.h>
void main()
{
   char st[100];
   int va=0,ve=0,vi=0,vo=0,vu=0,l=0;
   char ch='a';
   printf("Enter the text:");
   gets(st);
   l=strlen(st);
   for(int i=0;i<l;i++)
   {
        ch=st[i];
        if(ch=='a' || ch=='A')
            va++;  
        if(ch=='e' || ch=='E')
            ve++;
        if(ch=='i' || ch=='I')
            vi++;
        if(ch=='o' || ch=='O')
            vo++;   
        if(ch=='u' || ch=='U')
            vu++;
    }    
   printf("\nNo.of vowels A %d",va);
   printf("\nNo.of vowels E %d",ve);
   printf("\nNo.of vowels I %d",vi);
   printf("\nNo.of vowels O %d",vo);
   printf("\nNo.of vowels U %d",vu);
}
