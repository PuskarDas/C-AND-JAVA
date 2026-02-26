#include <stdio.h>
int a[11];
int rear=-1, front=0, max=11;
void PUSH(int n)
{
    if(rear<max)
    {
        rear++;
        a[rear]=n;
    }
    else
        printf("\nStack FULL !!");
}
int POP()
{
    if(rear>=front)
    {
        int temp=a[rear];
        rear--;
        return temp;
    }
    else
    {
        printf("\nStack EMPTY !!");
        return (-1);
    }
}
void showstack()
{
    if(rear>=front)
    {
        printf("\nThe Stack: ");
        for(int i=front;i<=rear;i++)
            printf("%d, ",a[i]);
    }
    else
        printf("\nStack EMPTY !!");
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