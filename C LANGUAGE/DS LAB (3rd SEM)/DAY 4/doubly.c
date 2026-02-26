#include <stdio.h>
#include <stdlib.h>  
struct Node
{
    int a;
    struct Node *next;
    struct Node *prev;
};
struct Node *start=NULL;
int isEmpty()                  //to check if inked list is empty or not          
{
    return start==NULL;
} 
void ForwardTraversal()               
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
void BackwardTraversal()
{
    if(!start)
        printf("\nList is Empty");
    struct Node *temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    while(temp!=NULL)
    {   
        printf("%d ",temp->a);
        temp=temp->prev;
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
void InsertBegin(int data)
{
    struct Node *temp=start;
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->a=data;
    newNode->next=start;
    newNode->prev=NULL;
    //temp->prev=newNode;
    start=newNode;
}
void Insertlast(int data)
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
void InsertPosition(int data,int pos)
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
int main()                          //main fuction to call all the DLL operations
{
    int choice=0,value,position,key;
    while(choice!=13)               //input MENU CHOICE for user to choose
    {
        printf("\n");
        printf("\n---MENU CHOICE---\n");
        printf("1. Forward Traversal \n");
        printf("2. Backward Traversal \n");
        printf("3. Empty Checking\n");
        printf("4. Insert at Beginning\n");
        printf("5. Insert at End\n");
        printf("6. Insert at Position\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete from End\n");
        printf("9. Delete from Position\n");
        printf("10. Delete by Key\n");
        printf("11. Total number of Nodes\n");
        printf("12. Search Element\n");
        printf("13. Quit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1:
                ForwardTraversal();
                break;
            case 2:
                BackwardTraversal();
                break;
            case 3:
                if(isEmpty())
                    printf("\nList is empty");
                else
                    printf("\nList is not empty");
                break;
            case 4:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                InsertBegin(value);
                break;
            case 5:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                Insertlast(value);
                break;
            case 6:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                printf("\nEnter Position to insert: ");
                scanf("%d",&position);
                InsertPosition(value,position);
                break;
            case 7:
                DeleteFirst();
                break;
            case 8:
                Deletelast();
                break;
            case 9:
                printf("Enter Position to delete: ");
                scanf("%d",&position);
                DeletePosition(position);
                break;
            case 10:
                printf("Enter key/value to delete: ");
                scanf("%d",&key);
                DeleteKey(key);
                break;
            case 11:
                printf("\nThe total number of nodes: %d",CountNode());
                break;
            case 12:
                printf("Enter element to search: ");
                scanf("%d",&key);
                Search(key);
                break;
            case 13:
                free(start);
                printf("The linked list is deleted and memory is deallocated.");
                break;
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}