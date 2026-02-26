#include<stdio.h>                                              
#include<stdlib.h>                      
struct Node                    //to create a node in Singly linked list
{   
    int data;  
    struct Node *next;    
};  
struct Node *start=NULL;      
int isEmpty()                  //to check if inked list is empty or not          
{
    return start==NULL;
} 
void Traversal()               //to traverse through the linked list
{
    if(isEmpty())
        printf("\nList is Empty");    

    struct Node *current=start;
    while(current!=NULL)
    {
        printf("%d ",current->data);  
        current=current->next;
    }
    printf("\n");
}
int CountNode()                //to count the no.of nodes in the linked list
{
    int count=0;
    struct Node *current=start;                                         
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}
void InsertBegin(int value)    //to insert node at the beginning
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node)); 
    newNode->data=value;
    newNode->next=start;
    start=newNode;
}
void Insertlast(int value)    //to insert node at the end 
{   
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    
    if(isEmpty())
        start=newNode;

    struct Node *temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}   
void InsertPosition(int value,int pos)    //to insert node at desired position
{
    if(pos==1)
    {
        InsertBegin(value);
        return;
    }
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;

    struct Node *temp=start;
    for(int i=1;i<pos-1;i++)
        temp=temp->next;
    newNode->next=temp->next;
    temp->next=newNode;
}
void DeleteFirst()                //to delete first node of linked list
{
    if(isEmpty())
        printf("\nList is Empty");
    
    struct Node *temp=start;
    start=start->next;
    free(temp);
}
void DeleteLast()                //to delete last node of linked list
{
    if(isEmpty())
        printf("\nList is Empty");
    
    else if(start->next==NULL)
    {
        free(start);
        start=NULL;
    }

    struct Node *current=start;
    while(current->next->next!=NULL)
        current=current->next;
    free(current->next);
    current->next=NULL;
}
void DeletePosition(int pos)      //to delete node at a desired position 
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
    free(current);
}
void DeleteKey(int key)            //to delete node by value assigned 
{
    if(isEmpty())
        printf("\nList is Empty");
    else if(start->data==key)
        DeleteFirst();

    struct Node *temp=start;
    while(temp->next!=NULL && temp->next->data!=key)
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
        free(current);
    }
}
void Search(int value)              //to search an element in a linked list
{
    struct Node *current=start;
    int pos=1;
    while(current!=NULL) 
    {
        if(current->data==value) 
        {
            printf("Element %d found at position %d.\n",value,pos);
            return;
        }
        current=current->next;
        pos++;
    }
    printf("Element not found.\n");
}

int main()                           //main fuction to call all the SLL operations
{
    int choice=0,value,position,key;
    while(choice!=12)               //input MENU CHOICE for user to choose
    {
        printf("\n");
        printf("\n---MENU CHOICE---\n");
        printf("1. Traverse List\n");
        printf("2. Empty Checking\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Delete by Key\n");
        printf("10. Total number of Nodes\n");
        printf("11. Search Element\n");
        printf("12. Quit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1:
                Traversal();
                break;
            case 2:
                if(isEmpty())
                    printf("\nList is empty");
                else
                    printf("\nList is not empty");
                break;
            case 3:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                InsertBegin(value);
                break;
            case 4:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                Insertlast(value);
                break;
            case 5:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                printf("\nEnter Position to insert: ");
                scanf("%d",&position);
                InsertPosition(value,position);
                break;
            case 6:
                DeleteFirst();
                break;
            case 7:
                DeleteLast();
                break;
            case 8:
                printf("Enter Position to delete: ");
                scanf("%d",&position);
                DeletePosition(position);
                break;
            case 9:
                printf("Enter key/value to delete: ");
                scanf("%d",&key);
                DeleteKey(key);
                break;
            case 10:
                printf("\nThe total number of nodes: %d",CountNode());
                break;
            case 11:
                printf("Enter element to search: ");
                scanf("%d",&key);
                Search(key);
                break;
            case 12:
                free(start);
                printf("The linked list is deleted and memory is deallocated.");
                break;
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}