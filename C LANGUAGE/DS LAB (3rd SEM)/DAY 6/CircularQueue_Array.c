#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front=-1,rear=-1;
int isEmpty() 
{
    return front==-1;
}
int isFull() 
{
    return (rear+1)%SIZE==front;
}
void Enqueue(int value) 
{
    if(isFull()) 
    {
        printf("Queue is FULL\n"); 
        return;
    }
    if(isEmpty()) 
        front=rear=0;
    else
        rear=(rear+1)%SIZE;
    queue[rear]=value;
    printf("%d enqueued successfully\n",value);
}
void Dequeue() 
{
    if(isEmpty()) 
    {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("%d dequeued successfully\n",queue[front]);
    if(front==rear)
        front=rear= -1;           // Reset queue
    else
        front=(front+1)%SIZE;
}
void Peek() 
{
    if(isEmpty())
        printf("Queue is EMPTY\n");
    else 
        printf("Front element: %d\n",queue[front]);
}
void Display() 
{
    if(isEmpty()) 
    {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Queue elements: ");
    int i=front;
    while(1) 
    {
        printf("%d ",queue[i]);
        if(i==rear) 
            break;
        i=(i+1)%SIZE;
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
