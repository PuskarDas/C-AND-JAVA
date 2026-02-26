#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start;
void Addfront(int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=start;
    start=newNode;
}
void Search(struct Node *st, int n)
{
    int c=0, found=0;
    while(st!=NULL)
    {
        if(n==st->a)
        {
            printf("\nValue found at : %d",c+1);
            found=1;
        }
        st=st->next;
        c++;
    }
    if(found==0)
        printf("\nValue not found");
}

int main()
{
    int s;
    Addfront(5);
    Addfront(10);
    Addfront(15);
    Addfront(20);
    printf("\nEnter value to search: ");
    scanf("%d",&s);
    Search(start,s);
    return 0;
}
