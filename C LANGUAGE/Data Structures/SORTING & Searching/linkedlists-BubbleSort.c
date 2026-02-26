#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start=NULL;
void Addfront(int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node)); 
    newNode->a=x;
    newNode->next=start;
    start=newNode;
}
void SWAP(struct Node *p1,struct Node *p2)
{
    int temp=p1->a;
    p1->a=p2->a;
    p2->a=temp;
}
void BubblesortInc()
{
    int swap;
    struct Node *ptr=start;
    do
    {
        swap=0;
        ptr=start;
        while(ptr->next!=NULL)
        {
            if(ptr->a>ptr->next->a)
            {
                SWAP(ptr,ptr->next);
                swap=1;
            }
            ptr=ptr->next;
        }
    } 
    while(swap);
}
void BubblesortDec()
{
    int swap;
    struct Node *ptr=start;
    do
    {
        swap=0;
        ptr=start;
        while(ptr->next!=NULL)
        {
            if(ptr->a<ptr->next->a)
            {
                SWAP(ptr,ptr->next);
                swap=1;
            }
            ptr=ptr->next;
        }
    } 
    while(swap);
}
void Printlist(struct Node *st)
{
    int c=0;
    while(st!=NULL)
    {
        printf("%d, ",st->a);
        st=st->next;
        c++;
    }
    printf("\nNo.of nodes: %d",c);
}

int main()
{
    Addfront(15);
    Addfront(10);
    Addfront(1);
    Addfront(2);
    Addfront(4);
    printf("\nBefore sorting :- ");
    Printlist(start);

    BubblesortInc();
    printf("\n");
    printf("\nAfter sorting in Increasing order:- ");
    Printlist(start);
    
    BubblesortDec();
    printf("\n");
    printf("\nAfter sorting in Decreasing order:- ");
    Printlist(start);
    return 0;
}
