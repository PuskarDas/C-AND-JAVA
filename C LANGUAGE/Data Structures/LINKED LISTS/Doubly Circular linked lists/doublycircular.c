#include <stdio.h>  
#include <stdlib.h>  
struct Node
{
    int a;
    struct Node *next;
    struct Node *prev;
};
struct Node *start;
void Traversal()               
{
    if(start==NULL)
    {
        printf("\nList is Empty");
        return;
    }
    struct Node *temp=start;
    do
    {
        printf("%d ",temp->a);  
        temp=temp->next;
    } while(temp!=start);
    printf("\n");
}
void Search(int value)
{
    struct Node *temp=start;
    int pos=1;
    do 
    {
        if(temp->a==value) 
        {
            printf("Element %d found at position %d.\n",value,pos);
            return;
        }
        temp=temp->next;
        pos++;
    } while(temp!=start);
    printf("Element not found.\n");
}
int CountNode()
{
    int count=0;
    struct Node *temp=start;                                         
    do
    {
        count++;
        temp=temp->next;
    } while(temp!=start);
    return count;
}
void Reverse() 
{
    if(!start || start->next==start) 
        return;

    struct Node *current=start;
    struct Node *temp=NULL;
    do
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;

        current=current->prev;
    } while(current!=start); 
    start=start->next; 
}
void InsertBegin(int data)
{
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->a=data;

    if(start==NULL) 
    {
        newNode->next=newNode;
        newNode->prev=newNode;
        start=newNode;
        return;
    }
    struct Node *tail=start->prev;
    newNode->next=start;
    newNode->prev=tail;
    tail->next=newNode;
    start->prev=newNode;
    start=newNode;
}
void InsertLast(int data)
{
    struct Node *temp=start;
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->a=data;
    newNode->next=start;

    start->prev=newNode;
    while(temp->next!=start)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void Insertposition(int data,int pos)
{
    if(pos==1)
    {
        InsertBegin(data);
        return;
    }
    else if(pos==(CountNode()+1))
    {
        InsertLast(data);
        return;
    }
    else if(pos>CountNode())
    {
        printf("\nInvalid Position !");
        return;
    }
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->a=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    struct Node *temp=start;
    for(int i=1;i<pos-1;i++)
        temp=temp->next;
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
}
void DeleteFirst()
{
    struct Node *temp=start;
    if(start==NULL)
        return;
    temp=temp->next;
    temp->prev=start->prev;
    struct Node *last=start;
    do
    {
        last=last->next;
    } while(last->next!=start);
    last->next=temp;
    start=start->next;
}
void Deletelast()
{
    if(start==NULL)
        return; 
    struct Node *last=start;
    struct Node *slast=start;
    for(int i=1;i<CountNode();i++)
    {
        slast=last;
        last=last->next;
    }
    slast->next=last->next; 
    start->prev=slast;
}
void DeletePosition(int pos)
{
    if(pos==1)
    {
        DeleteFirst();
        return;
    }
    else if(pos==(CountNode()+1))
    {
        Deletelast();
        return;
    }
    else if(pos>CountNode())
    {
        printf("\nInvalid Position !");
        return;
    }
    struct Node *temp=start;
    for(int i=1;i<pos-1;i++)
        temp=temp->next;

    struct Node *current=temp->next;
    temp->next=current->next;
    current->prev=temp;
    free(current);
}
void DeleteKey(int key)
{
    if(!start) 
        return;
    struct Node *temp=start;
    do 
    {
        if(temp->a==key) 
        {
            if(temp==start)
                DeleteFirst();
            else if(temp->next==start)
                Deletelast();
            else 
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
            }
            return;
        }
        temp=temp->next;
    } while(temp!=start);
}
int main()
{
    int posn,key,search;
    InsertBegin(5);
    InsertLast(10);
    InsertLast(15);
    InsertLast(20);
    InsertLast(25);
    InsertLast(30);
    Traversal();
    printf("No.of nodes: %d",CountNode());
    //printf("\nEnter posn to delete: ");
    //scanf("%d",&posn);
    //DeletePosition(posn);
    //printf("\n");
    //Traversal();
    //printf("No.of nodes: %d",CountNode());
    //printf("\n");

    //Deletefirst();
    //Deletelast();
    //Traversal();
    //printf("No.of nodes: %d",CountNode());
    printf("\nEnter element to delete: ");
    scanf("%d",&key);
    DeleteKey(key);
    Traversal();
    printf("No.of nodes: %d",CountNode());
    //printf("\nReversed linked list:- ");
    //Reverse();
    //Traversal();
    return 0;
}