#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
struct Node* top=NULL;
int isEmpty() 
{
    return top==NULL;
}
void Display() 
{
    if(isEmpty()) 
        printf("Stack is empty.\n");
    else 
    {
        struct Node *temp=top;
        printf("Stack elements:\n");
        while(temp!=NULL) 
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void PUSH(int value) 
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode) 
    {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }
    newNode->data=value;
    newNode->next=top->next;
    top=newNode;
    printf("%d pushed onto the stack.\n",value);
}
void POP() 
{
    if(isEmpty()) 
        printf("Stack underflow\n");
    else 
    {
        struct Node *temp=top;
        printf("%d popped from the stack.\n",temp->data);
        top=top->next;
        free(temp);
    }
}
int main() 
{
    int choice,value;
    while(choice!=5) 
    {
        printf("\n--- Stack Menu ---\n");
        printf("1.Check if stack is empty\n");
        printf("2.Display stack elements\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) 
        {
            case 1:
                if (isEmpty())
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 2:
                Display();
                break;
            case 3:
                printf("Enter value to push: ");
                scanf("%d", &value);
                PUSH(value);
                break;
            case 4:
                POP();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}