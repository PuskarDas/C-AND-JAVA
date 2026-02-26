#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start;
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