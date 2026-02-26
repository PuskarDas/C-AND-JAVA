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
int NodeSearch(struct Node *root,int key) 
{
    if(root==NULL)
        return 0;
    if(root->a==key)
        return 1;

    int result1=NodeSearch(root->left,key);
    if (result1) return 1;

    int result2=NodeSearch(root->right,key);
    return result2;
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

    int key=5;
    if(NodeSearch(tree,key))
        printf("TRUE !!");
    else
        printf("FALSE !!");
    return 0;
}