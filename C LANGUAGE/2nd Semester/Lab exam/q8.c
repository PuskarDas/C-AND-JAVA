#include <stdio.h>
#include <string.h>
void concatenate(char *st1,char *st2)
{
    while(*st1!='\0')
        st1++;
    while(*st2!='\0')
        *st1=*st2;
        st1++;
        st2++;
}
int main()
{
    char st1[100],st2[100];
    printf("\nEnter the 1st string:");
    gets(st1);
    printf("\nEnter the 2nd string:");
    gets(st2);

    st1[strcspn(st1,"\n")]='\0';
    st2[strcspn(st2,"\n")]='\0';

    concatenate(st1,st2);
    printf("concatenated string:%s\n",st1);
    return 0;
}