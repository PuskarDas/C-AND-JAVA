#include <stdio.h>
int a[11];
int rear=-1, front=0, max=9;
void PUSH(int n)
{
    if(rear<max)
    {
        rear++;
        a[rear]=n;
    }
    else
        printf("\nQueue FULL !!");
}
int POP()
{
    if(rear>=0)
    {
        int temp=a[front];
        for(int i=front;i<rear;i++)
        {
            a[i]=a[i+1];
        }
        rear--;
        return temp;
    }
    else
    {
        printf("\nQueue EMPTY !!");
        return (-1);
    }
}
void showstack()
{
    if(rear>=front)
    {
        printf("\nThe Queue: ");
        for(int i=front;i<=rear;i++)
            printf("%d, ",a[i]);
    }
    else
        printf("\nQueue EMPTY !!");
}
int main()
{
    int e;
    printf("Enter array element:");
    scanf("%d",&e);
    PUSH(1);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    showstack();
    e=POP();
    printf("\nPopped: %d",e);
    showstack();
    e=POP();
    printf("\nPopped: %d",e);
    showstack();
    return 0;
}
