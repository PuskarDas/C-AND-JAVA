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
int Level(struct Node *root,struct Node *node,int level) 
{
    if(root==NULL)
        return 0;
    if(root==node)
        return level;
    int downlevel=Level(root->left,node,level+1);
    if(downlevel!=0)
        return downlevel;
    else
        return Level(root->right,node,level+1);
}
void printLevel(struct Node *root,struct Node *node,int level) 
{
    if(root==NULL || level<2)
        return;
    if(level==2) 
    {
        if(root->left==node || root->right==node)
            return;
        if(root->left)
            printf("%d ",root->left->a);
        if(root->right)
            printf("%d ",root->right->a);
    }
    else if(level>2) 
    {
        printLevel(root->left,node,level-1);
        printLevel(root->right,node,level-1);
    }
}
void Cousins(struct Node *root,struct Node *node) 
{
    int level=Level(root,node,1);
    printLevel(root,node,level);
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

    Cousins(tree,tree->left->left);
    return 0;
} 