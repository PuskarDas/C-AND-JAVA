#include <stdio.h>
#define MAX 100

int stack[MAX];
int top=-1;
int isEmpty() 
{
    return top==-1;
}
void Display() 
{
    if(isEmpty())
        printf("Stack is empty.\n");
    else 
    {
        printf("Stack elements:\n");
        for(int i=top;i>=0;i--) 
            printf("%d\n",stack[i]);
    }
}
void PUSH(int value) 
{
    if(top==MAX-1) 
        printf("Stack overflow\n",value);
    else 
    {
        stack[++top]=value;
        printf("%d pushed onto the stack\n",value);
    }
}
void POP() 
{
    if(isEmpty()) 
        printf("Stack underflow\n");
    else
        printf("%d popped from the stack\n",stack[top--]);
}
int main() 
{
    int choice,value;
    while(choice!=5) 
    {
        printf("\n--- Stack Menu ---\n");
        printf("1.Check if stack is empty\n");
        printf("2.Display stack elements\n");
        printf("3.Push\n");
        printf("4.Pop\n");
        printf("5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) 
        {
            case 1:
                if(isEmpty())
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 2:
                Display();
                break;
            case 3:
                printf("Enter value to push: ");
                scanf("%d",&value);
                PUSH(value);
                break;
            case 4:
                POP();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}