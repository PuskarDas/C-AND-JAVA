#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start=NULL;
void Addfront(struct Node **start,int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=*start;
    *start=newNode;
}
struct Node *MergeSortInc(struct Node *l1,struct Node *l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    if(l1->a<l2->a)
    {
        l1->next=MergeSortInc(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next=MergeSortInc(l1,l2->next);
        return l2;
    }
}
struct Node *MergeSortDec(struct Node *l1,struct Node *l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    if(l1->a>l2->a)
    {
        l1->next=MergeSortDec(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next=MergeSortDec(l1,l2->next);
        return l2;
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
    struct Node *list1=NULL;
    struct Node *list2=NULL;

    //Input 2 already sorted linked lists in Increasing order
    Addfront(&list1,5);
    Addfront(&list1,2);

    Addfront(&list2,17);
    Addfront(&list2,9);
    Addfront(&list2,8);
    
    struct Node *x=MergeSortInc(list1,list2);
    printf("\nAfter Merge Sorting in Increasing order :- ");
    Printlist(x);
    printf("\n");

    struct Node *list3=NULL;
    struct Node *list4=NULL;

    //Input 2 already sorted linked lists in Decreasing order
    Addfront(&list3,2);
    Addfront(&list3,5);

    Addfront(&list4,8);
    Addfront(&list4,9);
    Addfront(&list4,17);
    
    struct Node *y=MergeSortDec(list3,list4);
    printf("\nAfter Merge Sorting in Decreasing order :- ");
    Printlist(y);
    return 0;
}
