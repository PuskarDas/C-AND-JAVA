#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start;
void PUSH(int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=start;
    start=newNode;
}
int POP()
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
void PrintQueue(struct Node *st)
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
    PUSH(5);
    PUSH(10);
    PUSH(15);
    PUSH(20);
    PrintQueue(start);

    printf("\n");
    POP();
    printf("\nAFTER POPING:-");
    PrintQueue(start);
    return 0;
}
