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
void SelectionsortInc()
{
    for(struct Node *ptr=start;ptr!=NULL;ptr=ptr->next)
    {        
        struct Node *min=ptr;
        for(struct Node *curr=ptr->next;curr!=NULL;curr=curr->next)
        {
            if(min->a>curr->a)
                min=curr;
        }
        SWAP(min,ptr);
    }
}
void SelectionsortDec()
{
    for(struct Node *ptr=start;ptr!=NULL;ptr=ptr->next)
    {        
        struct Node *max=ptr;
        for(struct Node *curr=ptr->next;curr!=NULL;curr=curr->next)
        {
            if(max->a<curr->a)
                max=curr;
        }
        SWAP(max,ptr);
    }
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

    SelectionsortInc();
    printf("\n");
    printf("\nAfter sorting in Increasing order:- ");
    Printlist(start);
    
    SelectionsortDec();
    printf("\n");
    printf("\nAfter sorting in Decreasing order:- ");
    Printlist(start);
    return 0;
}
