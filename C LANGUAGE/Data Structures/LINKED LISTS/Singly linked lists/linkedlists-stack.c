#include <stdio.h>
#include <stdlib.h>
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
    PUSH(5);
    PUSH(10);
    PUSH(15);
    PUSH(20);
    PrintStack(start);

    printf("\n");
    POP();
    printf("\nAFTER POPING:-");
    PrintStack(start);
    return 0;
}
