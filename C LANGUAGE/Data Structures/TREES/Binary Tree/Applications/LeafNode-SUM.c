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
void LeafSum(struct Node *root,int *SUM) 
{
    if(!root)
        return;
    if(!root->left && !root->right)
        *SUM+=root->a;
    LeafSum(root->left,SUM);
    LeafSum(root->right,SUM);
}

int main()
{
    int sum=0;
    
    struct Node *tree=NULL;
    tree=NewNode(1);
    tree->left=NewNode(2);
    tree->right=NewNode(3);
    tree->left->left=NewNode(4);
    tree->left->right=NewNode(5);
    tree->right->left=NewNode(6);
    tree->right->right=NewNode(7);

    LeafSum(tree,&sum);
    printf("\nSum of all leaf nodes is: %d",sum);
    return 0;
}
