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
void LeafNode(struct Node *root) 
{
    if(!root)
        return;
    if(!root->left && !root->right) 
    {
        printf("%d, ",root->a);
        return;
    }
    if(root->left)
        LeafNode(root->left);
    if(root->right)
        LeafNode(root->right);
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

    printf("\nAll Leaf Nodes are :- ");
    LeafNode(tree);
    return 0;
} 