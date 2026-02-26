#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
/*void showstack()
{
    if(rear>=front)
    {
        printf("\nThe Stack: ");
        for(int i=front;i<=rear;i++)
            printf("%d, ",a[i]);
    }
    else
        printf("\nStack EMPTY !!");
}*/
int main()
{
    char ar[100];
    int result=0;
    printf("\nEnter the postfix expressions: ");
    gets(ar);
    int l=strlen(ar);
    for (int i=0;i<l;i++)
    {
        char x=ar[i];
        int y=x-'0';
        if(isdigit(x))
            PUSH(y);
        else
        {
            int v1=POP();
            int v2=POP();
            switch(x)
            {
                case '+':
                    result=v2+v1;
                    PUSH(result);
                    break;
                case '-':
                    PUSH(v2-v1);
                    break;
                case '*':
                    PUSH(v2*v1);
                    break;
                case '/':
                    PUSH(v2/v1);
                    break;
                default :
                    printf("Invalid operator !!");
            }
        }
    }
    result=POP();
    printf("\nThe result: %d",result);
    return result;
}
