#include <stdio.h>
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
void DoubleOrder(struct Node *root) 
{
    if (root==NULL) 
        return;
    printf("%d, ",root->a);

    DoubleOrder(root->left);
    printf("%d, ",root->a);
    DoubleOrder(root->right);
}

int main() 
{
    struct Node *tree;
    tree=NewNode(1);
    tree->left=NewNode(7);
    tree->right=NewNode(3);
    tree->left->left=NewNode(4);
    tree->left->right=NewNode(5);
    tree->right->left=NewNode(6);

    DoubleOrder(tree);
    return 0;
}