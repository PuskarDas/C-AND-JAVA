#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start;
void Addfront(struct Node **start,int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=*start;
    *start=newNode;
}
int getMax(struct Node *start) 
{
    int max=start->a;
    while(start) 
    {
        if(start->a>max)
            max=start->a;
        start=start->next;
    }
    return max;
}
void countingSort_Inc(struct Node **start,int exp) 
{
    struct Node *bucket[10]={NULL};
    struct Node *End[10]={NULL};
    struct Node *current=*start;
    while(current) 
    {
        int index=(current->a/exp)%10;
        if(!bucket[index]) 
            bucket[index]=End[index]=current;
        else 
        {
            End[index]->next=current;
            End[index]=current;
        }
        current=current->next;
    }
    struct Node *newStart=NULL;
    struct Node *newEnd=NULL;
    for (int i=0;i<10;i++) 
    {
        if(bucket[i]) 
        {
            if(!newStart) 
            {
                newStart=bucket[i];
                newEnd=End[i];
            } 
            else 
            {
                newEnd->next=bucket[i];
                newEnd=End[i];
            }
        }
    }
    if (newEnd) newEnd->next=NULL;
    *start=newStart;
}
void RadixSortInc(struct Node **start) 
{
    int max=getMax(*start);
    for(int exp=1;max/exp>0;exp*=10)
        countingSort_Inc(start,exp);
}
void countingSort_Dec(struct Node** start, int exp) 
{
    struct Node *bucket[10]={NULL}; 
    struct Node *End[10]={NULL};    
    struct Node *current=*start;
     while(current) 
     {
        int index=(current->a/exp)%10;
        if(!bucket[index])
            bucket[index]=End[index]=current;
        else 
        {
            End[index]->next=current;
            End[index]=current;
        }
        current=current->next;
    }
    struct Node *newStart=NULL;
    struct Node *newEnd=NULL;
    for(int i=9;i>=0;i--) 
    { 
        if(bucket[i]) 
        {
            if(!newStart) 
            {
                newStart=bucket[i];
                newEnd=End[i];
            } else {
                newEnd->next=bucket[i];
                newEnd=End[i];
            }
        }
    }
    if(newEnd)newEnd->next=NULL;
    *start=newStart;
}
void RadixSortDec(struct Node **start) 
{
    int max=getMax(*start);
    for(int exp=1;max/exp>0;exp*=10)
        countingSort_Dec(start,exp);
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
    RadixSortInc(&list);
    printf("After Sorting in Increasing Order :-");
    Printlist(list);

    printf("\n");
    RadixSortDec(&list);
    printf("After Sorting in Decreasing Order:-");
    Printlist(list);
    return 0;
}