/*#include <stdio.h>
#include <stdlib.h>
struct StackNode 
{
    int data;
    struct StackNode* next;
};
struct Stack 
{
    struct StackNode* top;
};
struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}
// Function to push an element onto the stack while maintaining monotonicity (increasing)
void pushMonotonicIncreasing(struct Stack* stack, int data) {
    while (!isEmpty(stack) && stack->top->data > data) {
        struct StackNode* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    struct StackNode* stackNode = newNode(data);
    stackNode->next = stack->top;
    stack->top = stackNode;
}
// Function to push an element onto the stack while maintaining monotonicity (decreasing)
void pushMonotonicDecreasing(struct Stack* stack, int data) {
     while (!isEmpty(stack) && stack->top->data < data) {
        struct StackNode* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    struct StackNode* stackNode = newNode(data);
    stackNode->next = stack->top;
    stack->top = stackNode;
}
int pop(struct Stack* stack) 
{
    if (isEmpty(stack))
        return -1; 
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
// Function to peek at the top element of the stack
int peek(struct Stack* stack) 
{
     if (isEmpty(stack))
        return -1;
    return stack->top->data;
}

int main() 
{
    struct Stack* increasingStack = createStack();
    pushMonotonicIncreasing(increasingStack, 3);
    pushMonotonicIncreasing(increasingStack, 1);
    pushMonotonicIncreasing(increasingStack, 4);
    pushMonotonicIncreasing(increasingStack, 2);

    printf("Monotonic Increasing Stack: ");
    while (!isEmpty(increasingStack)) 
    {
        printf("\n%d ", pop(increasingStack));
    }
    printf("\n");

    struct Stack* decreasingStack = createStack();
    pushMonotonicDecreasing(decreasingStack, 1);
    pushMonotonicDecreasing(decreasingStack, 5);
    pushMonotonicDecreasing(decreasingStack, 2);
    pushMonotonicDecreasing(decreasingStack, 4);

     printf("Monotonic Decreasing Stack: ");
    while (!isEmpty(decreasingStack)) 
    {
        printf("%d ", pop(decreasingStack));
    }
    printf("\n");
    return 0;
}*/

///////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Function to print the monotonic stack
void printStack(int stack[], int top) 
{
    printf("Monotonic Stack: ");
    for (int i = 0; i <= top; i++) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
// Function to maintain a monotonic increasing stack
void monotonicStack(int arr[], int n) 
{
    int stack[MAX], top = -1;
    for (int i = 0; i < n; i++) 
    {
        while (top >= 0 && stack[top] > arr[i]) 
        {
            top--; // Pop elements that break monotonicity
        }
        stack[++top] = arr[i]; // Push current element
        printStack(stack, top);
    }
}
// Function to maintain a monotonic decreasing stack
void monotonicStack(int arr[], int n) 
{
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++) 
    {
        while (top >= 0 && stack[top] < arr[i]) 
        {
            top--; // Pop elements that break monotonicity
        }
        stack[++top] = arr[i]; // Push current element
        printStack(stack, top);
    }
}

int main() 
{
    int arr[] = {3, 7, 2, 5, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    monotonicStack(arr, n);
    return 0;
}*/

////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start;
int arr[5]={1,7,9,5,8};
void PUSH(int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=start;
    start=newNode;
}
int POP()
{
    int temp=start->a;
    start=start->next;
    return temp;
}
bool isEmpty()
{
    if(start==NULL)
        return true;
    else 
        return false;
}
void MonotonicInc()
{
    int a=0,b=0;
    PUSH(arr[0]);
    for(int i=1;i<5;i++)
    {
        a=POP();
        while(arr[i]<a)
            a=POP();
        b=arr[i];
    }
    PUSH(a);
    PUSH(b);
}
void PrintStack(struct Node *st)
{
    int c=0;
    while(st!=NULL)
    {
        printf("\n%d",st->a);
        st=st->next;
        c++;
    }
    printf("\nNo.of nodes: %d",c);
}

int main()
{
    MonotonicInc();
    PrintStack(start);

    return 0;
}
