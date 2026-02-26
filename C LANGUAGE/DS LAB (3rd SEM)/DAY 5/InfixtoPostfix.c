#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top=-1;
void PUSH(char c) 
{
    stack[++top]=c;
}
char POP() 
{
    return stack[top--];
}
char PEEK() 
{
    return stack[top];
}
int isEmpty() 
{
    return top == -1;
}
int precedence(char op)          // Function to check precedence of operators
{
    switch(op) 
    {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
int isOperator(char c)         // Function to check if character is operator
{
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}
void InfixToPostfix(char *in,char *post) 
{
    int i=0,j=0;
    char c;
    while((c=in[i++])!='\0') 
    {
        if(isalnum(c)) 
            post[j++]=c;      // Operand goes directly to output
        else if(c=='(')
            PUSH(c);
        else if(c==')') 
        {
            while(!isEmpty() && PEEK()!='(') 
                post[j++]=POP();
            if(!isEmpty()) 
                POP();       // Remove '('
        } 
        else if(isOperator(c)) 
        {
            while(!isEmpty() && precedence(PEEK())>=precedence(c))
                post[j++]=POP();
            PUSH(c);
        }
    }
    while(!isEmpty())
        post[j++]=POP();
    post[j]='\0';           // Null-terminate the postfix string
}
int main() 
{
    char infix[MAX],postfix[MAX];

    printf("Enter Infix expression: ");
    scanf("%s",infix);

    InfixToPostfix(infix,postfix);
    printf("\n");
    printf("Equivalent Postfix expression: %s\n",postfix);
    return 0;
}