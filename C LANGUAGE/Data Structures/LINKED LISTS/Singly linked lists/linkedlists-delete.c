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
int Deletefront()
{
    int temp=start->a;
    start=start->next;
    return temp;
}
int Deletelast()
{
    struct Node *temp=start;
    struct Node *prev=start;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    int data=temp->a;
    prev->next=NULL;
    return data;
}
int Deletemiddle(int pos)
{
    struct Node *temp=start;
    struct Node *prev=start;
    for(int i=1;i<pos;i++) 
    {
        if(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
    }
    prev->next=temp->next;
}
void Printlist(struct Node *st)
{
    int c=0;
    while(st!=NULL)
    {
        printf("\n%d",st->a);
        st=st->next;
        c++;
    }
    printf("\nNo.of nodes: %d",c);
}

int main()
{
    Addfront(5);
    Addfront(10);
    Addfront(15);
    Addfront(20);
    Addfront(25);
    Addfront(30);
    Printlist(start);

    printf("\n");
    Deletemiddle(3);
    Deletefront();
    Deletelast();
    printf("\nAFTER DELETION:-");
    Printlist(start);
    return 0;
}
