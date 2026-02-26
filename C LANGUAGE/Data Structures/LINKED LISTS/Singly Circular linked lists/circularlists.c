#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start;
void Traversal()
{
    if(!start)
        printf("\nList is Empty");

    struct Node *current=start;
    while(current->next!=start)
    {
        printf("%d ",current->a);  
        current=current->next;
    }
    printf("\n");
}
int CountNode()                //to count the no.of nodes in the linked list
{
    int count=0;
    struct Node *current=start;                                         
    while(current->next!=start)
    {
        count++;
        current=current->next;
    }
    return count;
}
void Addfront(int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=NULL;
    
    if(start==NULL)
    {
        start=newNode;
        newNode->next=start;
    }
    else
    {
        struct Node *temp=start;
        while(temp->next!=start) 
            temp=temp->next;
        temp->next=newNode;
        newNode->next=start;
        start=newNode;
    }
}
void Addlast(int x)
{

    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=NULL;
    
    if(start==NULL) 
    {
        start=newNode;
        newNode->next=start;
    }
    else 
    {
        struct Node *temp=start;
        while(temp->next!=start) 
            temp=temp->next;
        temp->next=newNode;
        newNode->next=start;
    }
}
void AddPosition(int x,int pos)
{
    if(pos==1)
    {
        Addfront(x);
        return;
    }
    else if(pos==(CountNode()+1))
    {
        Addlast(x);
        return;
    }
    else if(pos>CountNode())
    {
        printf("\nInvalid Position !");
        return;
    }
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->a=x;

    struct Node *temp=start;
    for(int i=1;i<pos-1;i++)
        temp=temp->next;
    newNode->next=temp->next;
    temp->next=newNode;
}
void Deletefront()
{
    struct Node *temp=start;
    while(temp->next!=start) 
        temp=temp->next;
    temp->next=start->next;
    //struct Node *toDel=start;
    start=start->next;
}
void Deletelast()
{
    struct Node *slast=start;
    while(slast->next->next!=start) 
        slast=slast->next;
    //struct Node *last=slast->next;
    slast->next=start;
}
void DeletePosition(int pos)
{
    if(pos==1)
    {
        Deletefront();
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
    free(current);
}
/*void Printlist(struct Node *st)
{
    struct Node *temp=st;
    int c=0;
    do 
    {
        printf("\n%d",temp->a);
        temp=temp->next;
        c++;
    } while(temp!=st);
    printf("\nNo. of nodes: %d", c);
}*/
int search(int key)
{
    if (start==NULL)
        return 0;
    
    struct Node *temp=start;
    while(temp!=start); 
    {
        if (temp->a==key) 
            return 1; 
        temp=temp->next;
    }
    return 0; 
}
int main()
{
    int posn;
    Addfront(5);
    Addlast(10);
    Addlast(15);
    Addlast(20);
    Addlast(25);
    Addlast(30);
    Traversal();
    printf("No.of nodes: %d",CountNode());
    printf("\nEnter posn to insert: ");
    scanf("%d",&posn);
    AddPosition(35,posn);
    printf("\n");
    Traversal();
    printf("No.of nodes: %d",CountNode());
    //Printlist(start);
    return 0;
}
