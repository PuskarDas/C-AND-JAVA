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
    return top== -1;
}
void Reverse(char *str) 
{
    int len=strlen(str);
    for(int i=0;i<len/2;i++) 
    {
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
}
void SwapParentheses(char *expr) 
{
    for(int i=0;expr[i];i++) 
    {
        if(expr[i]=='(')
            expr[i]=')';
        else if(expr[i]==')')
            expr[i]='(';
    }
}
int precedence(char op)          // Function to check precedence of operators
{
    switch (op) 
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
void InfixToPostfix(char* in,char* post) 
{
    int i=0,j=0;
    char c;
    while((c=in[i++])!='\0') 
    {
        if(isalnum(c)) 
            post[j++]=c;  // Operand goes directly to output
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
    post[j]='\0';         // Null-terminate the postfix string
}
void InfixToPrefix(char* in,char* pre) 
{
    char rev[MAX],post[MAX];
    strcpy(rev,in);
    Reverse(rev);
    SwapParentheses(rev);

    InfixToPostfix(rev,post);
    Reverse(post);

    strcpy(pre,post);
}
int main() 
{
    char infix[MAX],prefix[MAX];

    printf("Enter Infix expression: ");
    scanf("%s",infix);

    InfixToPrefix(infix,prefix);

    printf("Equivalent Prefix expression: %s\n",prefix);
    return 0;
}
