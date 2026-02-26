#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *next;
};
void Addfront(struct Node **start,int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=*start;
    *start=newNode;
}
void SWAP(int *n1,int *n2)
{
    int temp=*n1;
    *n1=*n2;
    *n2=temp;
}
struct Node* getLast(struct Node *st) 
{
    while (st!=NULL && st->next!=NULL)
        st=st->next;
    return st;
}
struct Node *Partition_Inc(struct Node *first,struct Node *last)
{
    int pivot=last->a;
    struct Node *prev=first;
    struct Node *curr=first;

    while(curr!=last)
    {
        if(curr->a<pivot)
        {
            SWAP(&(prev->a),&(curr->a));
            prev=prev->next;
        }
        curr=curr->next;
    }
    SWAP(&(prev->a),&(last->a));
    return prev;
}
struct Node *QuickSortInc(struct Node *first,struct Node *last)
{
    if(first!=last && first!=NULL && last!=NULL)
    {
        struct Node *pivotNode=Partition_Inc(first,last);
        struct Node *temp=first;

        while(temp!=pivotNode && temp->next!=pivotNode)
            temp=temp->next;
        QuickSortInc(first,temp);
        QuickSortInc(pivotNode->next,last);
    }
}
struct Node *Partition_Dec(struct Node *first,struct Node *last)
{
    int pivot=last->a;
    struct Node *prev=first;
    struct Node *curr=first;

    while(curr!=last)
    {
        if(curr->a>pivot)
        {
            SWAP(&(prev->a),&(curr->a));
            prev=prev->next;
        }
        curr=curr->next;
    }
    SWAP(&(prev->a),&(last->a));
    return prev;
}
void QuickSortDec(struct Node *first,struct Node *last)
{
    if(first!=last && first!=NULL && last!=NULL)
    {
        struct Node *pivotNode=Partition_Dec(first,last);
        struct Node *temp=first;
        while(temp!=pivotNode && temp->next!=pivotNode)
            temp=temp->next;
        QuickSortDec(first,temp);
        QuickSortDec(pivotNode->next,last);
        //printf("Sorting from %d to %d\n", first->a, last->a);
        
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
    struct Node *list=NULL;
    Addfront(&list,5);
    Addfront(&list,2);
    Addfront(&list,17);
    Addfront(&list,9);
    Addfront(&list,8);
    printf("Before Sorting :-");
    Printlist(list);

    printf("\n");
    QuickSortInc(list,getLast(list));
    printf("After Sorting in Increasing Order :-");
    Printlist(list);

    printf("\n");
    QuickSortDec(list,getLast(list));
    printf("After Sorting in Decreasing Order:-");
    Printlist(list);
    return 0;
}
