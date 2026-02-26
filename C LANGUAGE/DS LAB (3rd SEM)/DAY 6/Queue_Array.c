#include<stdio.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
int isEmpty()
{
    return front==-1;
}
int isFull()
{
    return rear==MAX-1;
}
void Peek()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
    {
        printf("Front element: %d\n",queue[front]);
        return;
    }
}
void Display()
{
    if(isEmpty())
    {
        printf("\nQueue is empty");
        return;
    }
    printf("Queue Elements: ");
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
}
void Enqueue(int value)
{
    if(isFull())
    {
        printf("\nQueue is Full");
        return;
    }
    if(isEmpty())
        front=0;
    queue[++rear]=value;
    printf("\n %d enqueued",value);
}
void Dequeue()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty");
        return;
    }
    int x=queue[front];
    for(int i=front;i<rear;i++)         //shifting values
    {
        queue[i]=queue[i+1];
    }
    rear--;
    printf("%d dequeued succesfully",x);
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
                    printf("Queue is EMPTY");
                else
                    printf("Queue is not EMPTY");
                break;
            case 6:
                 if(isFull())
                    printf("Queue is FULL");
                else
                    printf("Queue is not FULL");
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