#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node 
{
    char a;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};
struct Node *start=NULL;
struct Node *newNode(char x)
{
    struct Node *Node;
    Node=(struct Node*)malloc(sizeof(struct Node));
    Node->a=x;
    Node->left=NULL;
    Node->right=NULL;
    Node->next=NULL;
    return Node; 
}
struct Node *InOrder(struct Node *root)
{
    if(root==NULL)
        return root;
    InOrder(root->left);
    printf("%c, ",root->a);
    InOrder(root->right);
}
struct Node *PostOrder(struct Node *root)
{
    if(root==NULL)
        return root;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c, ",root->a);
}
void PUSH(struct Node *key)
{
    if(start==NULL)
        start=key;
    else
    {
        key->next=start;
        start=key;
    }
    struct Node *temp;
}
struct Node *POP()
{
    struct Node *p=start;
    start=start->next;
    return p;
}
int main()
{
    char s[100];
    printf("\nEnter the expression: ");
    gets(s);
    int l=strlen(s);
    struct Node *x, *y, *z;
    for (int i=0;i<l;i++) 
    {
        if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^') 
        {
            z=newNode(s[i]);
            x=POP();
            y=POP();
            z->left=y;
            z->right=x;
            PUSH(z);
        }
        else 
        {
            z=newNode(s[i]);
            PUSH(z);
        }
    }
    printf("\nThe Infix of Expression Tree: ");
    InOrder(z);
    printf("\nThe Posfix Traversal of Expression Tree: ");
    PostOrder(z);
    return 0;
}
    
/*char s[100];
    printf("\nEnter the expression: ");
    gets(s);
    struct Node *x, *y, *z;  
    int l=strlen(s);
    for (int i=0;i<l;i++)
    {
        int x=s[i];
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
                    PUSH(v2+v1);
                    z=newNode(x);
                    break;
                case '-':
                    PUSH(v2-v1);
                    z=newNode(x);
                    break;
                case '*':
                    PUSH(v2*v1);
                    z=newNode(x);
                    break;
                case '/':
                    PUSH(v2/v1);
                    z=newNode(x);
                    break;
                default :
                    printf("Invalid operator !!");
            }
        }
    }
    result=POP();
    printf("\nThe result: %d",result);
    InOrder();*/