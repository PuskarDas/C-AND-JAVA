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
void LeftBoundary(struct Node *root,int *Sum) 
{
    if(root && (root->left || root->right)) 
    {
        *Sum+=root->a;
        if(root->left) 
            LeftBoundary(root->left,Sum);
        else
            LeftBoundary(root->right,Sum);
    }
}
void RightBoundary(struct Node *root,int *Sum) 
{
    if(root && (root->left || root->right)) 
    {
        if(root->right)
            RightBoundary(root->right,Sum);
        else 
            RightBoundary(root->left,Sum);
        *Sum+=root->a;
    }
}
void LeafSum(struct Node *root,int *Sum) 
{
    if(root) 
    {
        LeafSum(root->left,Sum);
        if(!(root->left) && !(root->right))
            *Sum+=root->a;
        LeafSum(root->right,Sum);
    }
}
int BoundarySum(struct Node *root) 
{
    if(!root)
        return 0;

    int bSUM=root->a;
    LeftBoundary(root->left,&bSUM);
        
    LeafSum(root->left,&bSUM);
    LeafSum(root->right,&bSUM);

    RightBoundary(root->right,&bSUM);
    return bSUM;
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
    tree->right->left->left=NewNode(8);

    printf("\nThe sum of all boundary nodes is: %d",BoundarySum(tree));
    return 0;
}