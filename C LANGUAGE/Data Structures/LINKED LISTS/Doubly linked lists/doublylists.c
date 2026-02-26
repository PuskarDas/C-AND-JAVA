#include <stdio.h>
#include <stdlib.h>  
struct Node
{
    int a;
    struct Node *next;
    struct Node *prev;
};
struct Node *start=NULL;
void Traversal()               
{
    if(!start)
        printf("\nList is Empty");
    struct Node *temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->a);  
        temp=temp->next;
    }
    printf("\n");
}
void Search(int value)
{
    struct Node *temp=start;
    int pos=1;
    while(temp!=NULL) 
    {
        if(temp->a==value) 
        {
            printf("Element %d found at position %d.\n",value,pos);
            return;
        }
        temp=temp->next;
        pos++;
    }
    printf("Element not found.\n");
}
int CountNode()
{
    int count=0;
    struct Node *temp=start;                                         
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void Infront(int data)
{
    struct Node *temp=start;
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->a=data;
    newNode->next=start;
    newNode->prev=NULL;
    //temp->prev=newNode;
    start=newNode;
}
void Inlast(int data)
{
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->a=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    struct Node *temp=start;
    
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void InPosition(int data,int pos)
{
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->a=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    struct Node *temp=start;
    for(int i=1;i<pos-1;i++)
        temp=temp->next;
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void DeleteFirst()
{
    struct Node *temp=start;
    start=start->next;
    start->prev=NULL;
    free(temp);
}
void Deletelast()
{
    struct Node *temp=start;
    while(temp->next->next!=NULL)
        temp=temp->next;
    temp->prev=NULL;
    free(temp);
}
void DeletePosition(int pos)
{
    if(pos==1)
    {
        DeleteFirst();
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
    if(start==NULL)
        printf("\nList is Empty");
    else if(start->a==key)
        DeleteFirst();

    struct Node *temp=start;
    while(temp->next!=NULL && temp->next->a!=key)
        temp=temp->next;

    if(temp->next==NULL) 
    {
        printf("Key not found.\n");
        return;
    }
    else
    {
        struct Node *current=temp->next;
        temp->next=current->next;
        current->prev=temp;
        free(current);
    }
}
/*void Printlist(struct Node *st)
{
    int c=0;
    while(st!=NULL)
    {
        printf("\n%d",st->a);
        st=st->next;
        c++;
    }
    printf("\nNo.of nodes: %d",c);
}*/
void PrintReverse(struct Node *st)
{
    int c=0;
    struct Node *temp=start;
    
    while(temp->next!=NULL)
        temp=temp->next;
    
    while(temp->prev!=NULL)
    {   
        printf("\n%d",temp->a);
        temp=temp->prev;
        c++;
    }
    printf("\nNo.of nodes: %d",c);
}
int main()
{
    int posn,search;
    Infront(5);
    Inlast(10);
    Inlast(15);
    Inlast(20);
    Inlast(25);
    Inlast(30);
    Traversal();
    printf("No.of nodes: %d",CountNode());
    printf("\n");
    printf("\nEnter position to insert: ");
    scanf("%d",&posn);
    InPosition(35,posn);
    Traversal();
    printf("No.of nodes: %d",CountNode());
    printf("\n");
    printf("\nEnter element to search: ");
    scanf("%d",&search);
    Search(search);
    printf("\n");
    printf("\nEnter position to delete: ");
    scanf("%d",&posn);
    DeletePosition(posn);
    Traversal();
    printf("No.of nodes: %d",CountNode());
    
    //printf("\n");
    //PrintReverse(start);
    return 0;
}