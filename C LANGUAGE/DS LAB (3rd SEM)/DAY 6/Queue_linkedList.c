#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;
int isEmpty() 
{
    return front==NULL;
}
void Enqueue(int value) 
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    
    if(rear==NULL)
        front=rear=newNode;
    else 
    {
        rear->next=newNode;
        rear=newNode;
    }
    printf("%d enqueued successfully.\n",value);
}
void Dequeue() 
{
    if(isEmpty()) 
    {
        printf("Queue is EMPTY\n");
        return;
    }
    struct Node *temp=front;
    printf("%d dequeued successfully.\n",temp->data);
    
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
}
void Peek() 
{
    if(isEmpty()) 
        printf("Queue is EMPTY\n");
    else 
        printf("Front element: %d\n",front->data);
}
void Display() 
{
    if(isEmpty()) 
    {
        printf("Queue is EMPTY.\n");
        return;
    }
    struct Node *temp=front;
    printf("Queue elements: ");
    while(temp!=NULL) 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() 
{
    int choice,value;

    while(choice!=7) 
    {
        printf("\n--- Queue Menu ---\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Empty\n");
        printf("6.Full\n");
        printf("7.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) 
        {
            case 1:
                printf("Enter value to Enqueue: ");
                scanf("%d",&value);
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Display();
                break;
            case 5:
                if(isEmpty())
                    printf("Queue is Empty");
                else
                    printf("Queue is not empty");
                break;
            case 6:
                printf("Queue can't be FULL in a linked list");
                break;
            case 7:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}