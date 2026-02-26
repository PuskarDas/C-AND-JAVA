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
void infixToPostfix(char* exp) 
{
    int len = strlen(exp);
    char result[len + 1];
    char stack[len];
    int j = 0;
    int top = -1;
    for (int i = 0; i < len; i++) 
    {
        char c = exp[i];
        if (isalnum(c))
            result[j++] = c;
        else if (c == '(')
            stack[++top] = '(';
        else if (c == ')') 
        {
            while (top != -1 && stack[top] != '(') 
                result[j++] = stack[top--];
            top--; 
        }
        else 
        {
            while (top != -1 && (prec(c) < prec(stack[top]) || prec(c) == prec(stack[top]))) 
                result[j++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top != -1) 
        result[j++] = stack[top--];
    result[j] = '\0';
    printf("%s\n", result);
}
