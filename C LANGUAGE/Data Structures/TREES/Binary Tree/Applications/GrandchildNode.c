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
void GrandChild(struct Node *root) 
{
    if(root==NULL)
        return;
    if(root->left!=NULL && root->right!=NULL) 
    {
        if(root->left->left!=NULL || root->left->right!=NULL || root->right->left!=NULL || root->right->right!=NULL) 
            printf("%d ",root->a);
    }
    else if(root->left!=NULL) 
    {
        if(root->left->left!=NULL || root->left->right!=NULL) 
            printf("%d ",root->a);
    }
    else if(root->right!=NULL) 
    {
        if(root->right->left!=NULL || root->right->right!=NULL) 
            printf("%d ",root->a);
    }
    GrandChild(root->left);
    GrandChild(root->right);
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

    printf("\nNode with Grandchilds is : ");
    GrandChild(tree);
    return 0;
} 