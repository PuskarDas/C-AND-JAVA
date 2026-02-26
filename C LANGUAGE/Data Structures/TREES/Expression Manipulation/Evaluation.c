#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    char a;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};
struct Node *start=NULL;
struct Node *NewNode(char x)
{
    struct Node *Node;
    Node=malloc(sizeof(struct Node));
    Node->a=x;
    Node->left=NULL;
    Node->right=NULL;
    Node->next=NULL;
    return Node; 
}
int Evaluation(struct Node *root)
{
    if(root==NULL)
    {
        printf("Return zero");
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        printf("Return root->a : %d",root->a);
        return root->a;
    }
    char x=root->a;
    switch(x)
            {
                case '+':
                    char r=root->left->a; //+ root->right->a;
                    printf("Return root->left->a + root->right->a : %d",r);
                    return r;
                    break;
                case '-':
                    return root->left->a - root->right->a;
                    break;
                case '*':
                    return root->left->a * root->right->a;    
                    break;
                case '/':
                    return root->left->a / root->right->a;
                    break;
                default :
                    printf("Invalid operator !!");
                    return 0;
            }
}
int main()
{
    struct Node *tree=NULL;
    tree=NewNode('+');
    tree->left=NewNode('*');
    tree->right=NewNode('-');
    tree->left->left=NewNode('5');
    tree->left->right=NewNode('4');
    tree->right->left=NewNode('8');
    tree->right->right=NewNode('/');
    tree->right->right->left=NewNode('2');
    tree->right->right->right=NewNode('1');

    printf("\nRESULT:- %d",Evaluation(tree));
    return 0;
}
