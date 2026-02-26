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
int PathSum(struct Node *root,int sum) 
{
    if(root==NULL) 
        return sum==0;
    int subSum=sum-root->a;
    if(subSum==0 && root->left==NULL && root->right==NULL) 
        return 1;

    return PathSum(root->left,subSum) || PathSum(root->right,subSum);
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

    int sum=11;
    if(PathSum(tree,sum)) 
        printf("True\n");
    else 
        printf("False\n");
    return 0;
}