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
struct Node *LeafDelete(struct Node *root) 
{
    if (root==NULL)
        return NULL;
    if (root->left==NULL && root->right==NULL) 
    {
        free(root);
        return NULL;
    }
    root->left=LeafDelete(root->left);
    root->right=LeafDelete(root->right);
    return root;
}
struct Node *InOrder(struct Node *root)
{
    if(root==NULL)
        return root;
    InOrder(root->left);
    printf("%d, ",root->a);
    InOrder(root->right);
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

    printf("\nBefore Deleting all leaf nodes:-\n");
    InOrder(tree);

    printf("\nAfter Deleting all leaf nodes:-\n");
    tree=LeafDelete(tree);
    InOrder(tree);
    return 0;
}
