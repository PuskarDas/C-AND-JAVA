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
void Addlast(int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=NULL;

    struct Node *temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}
void Addmiddle(int x,int pos)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;

    struct Node *temp=start;
    for(int i=2;i<pos;i++) 
    {
        if(temp->next!=NULL) 
            temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
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
    return 0;
}
