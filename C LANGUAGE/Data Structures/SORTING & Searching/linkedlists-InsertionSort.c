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
struct Node *InsertIncrease(struct Node *currNode,struct Node *sorted)
{
    if(sorted==NULL || sorted->a>=currNode->a)
    {
        currNode->next=sorted;
        sorted=currNode;
    }
    else
    {
        struct Node *ptr2=sorted;
        while(ptr2->next!=NULL && ptr2->next->a < currNode->a)
        {
            ptr2=ptr2->next;
        }
        currNode->next=ptr2->next;
        ptr2->next=currNode;
    }
    return sorted;
}
struct Node *InsertionSortInc(struct Node *start)
{
    struct Node *sorted=NULL;
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        struct Node *nextNode=ptr->next;
        sorted=InsertIncrease(ptr,sorted);
        ptr=nextNode;
    }
    return sorted;
}
struct Node *InsertDecrease(struct Node *currNode,struct Node *sorted)
{
    if(sorted==NULL || sorted->a < currNode->a)
    {
        currNode->next=sorted;
        sorted=currNode;
    }
    else
    {
        struct Node *ptr2=sorted;
        while(ptr2->next!=NULL && ptr2->next->a > currNode->a)
        {
            ptr2=ptr2->next;
        }
        currNode->next=ptr2->next;
        ptr2->next=currNode;
    }
    return sorted;
}
struct Node *InsertionSortDec(struct Node *start)
{
    struct Node *sorted=NULL;
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        struct Node *nextNode=ptr->next;
        sorted=InsertDecrease(ptr,sorted);
        ptr=nextNode;
    }
    return sorted;
}
void Printlist(struct Node *st)
{
    int c=0;
    struct Node *st2=st;
    while(st2!=NULL)
    {
        printf("%d, ",st2->a);
        st2=st2->next;
        c++;
    }
    printf("\nNo.of nodes: %d",c);
}

int main()
{
    Addfront(10);
    Addfront(15);
    Addfront(1);
    Addfront(2);
    Addfront(4);
    printf("\nBefore sorting :- ");
    Printlist(start);

    struct Node *x=InsertionSortInc(start);
    printf("\n");
    printf("\nAfter sorting in Increasing order:- ");
    Printlist(x);
    
    struct Node *y=InsertionSortDec(x);
    printf("\n");
    printf("\nAfter sorting in Decreasing order:- ");
    Printlist(y);
    return 0;
}