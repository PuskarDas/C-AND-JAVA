#include<stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *left;
    struct Node *right;
};
struct Node *NewNode(int x)
{
    struct Node *Node;
    Node=malloc(sizeof(struct Node));
    Node->a=x;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
int Ancestors(struct Node *root,int target) 
{
    if(root==NULL)
        return 0;
    if(root->a==target)
        return 1;
    if(Ancestors(root->left,target) || Ancestors(root->right,target)) 
    {
        printf("%d ",root->a);
        return 1;
    }
    return 0;
}

int main()
{
    struct Node *tree=NULL;
    tree=NewNode(1);
    tree->left=NewNode(2);
    tree->right=NewNode(3);
    tree->left->left=NewNode(4);
    tree->left->right=NewNode(5);
    tree->right->left=NewNode(6);
    tree->right->right=NewNode(7);
    tree->right->right->right=NewNode(8);
    printf("\nAncestor of 7:- ");
    Ancestors(tree,8);
    return 0;
} 