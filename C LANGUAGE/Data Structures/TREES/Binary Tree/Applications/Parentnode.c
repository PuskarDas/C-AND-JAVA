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
int FindParent(struct Node *root,int target,int parent) 
{
    if(root==NULL) 
        return -1;
    if(root->a==target) 
        return parent;

    int left_Search=FindParent(root->left,target,root->a);
    if (left_Search!=-1) 
        return left_Search;
    return FindParent(root->right,target,root->a);
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

    int target=6;
    int parent=FindParent(tree,target,-1);
    printf("%d\n",parent);
    return 0;
} 
