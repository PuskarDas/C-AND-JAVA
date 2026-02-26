#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char a;
    struct Node *left;
    struct Node *right;
};
struct Node *NewNode(char x)
{
    struct Node *Node;
    Node=malloc(sizeof(struct Node));
    Node->a=x;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
int Height(struct Node* root) 
{
    if(root==NULL)
        return 0;
    if(root->left==NULL)
        return 1+Height(root->right);
    if(root->right==NULL)
        return 1+Height(root->left);

    return 1+((Height(root->left)<Height(root->right))?
                Height(root->left):Height(root->right));
}
int Depth(struct Node *root,struct Node *target,int level) 
{
    if(root==NULL)
        return -1;
    if(root==target)
        return level;

    int leftDepth=Depth(root->left,target,level+1);
    if(leftDepth!= -1)
        return leftDepth;
    return Depth(root->right,target,level+1);
}

int main()
{
    struct Node *tree=NULL;
    /*tree=NewNode(1);
    tree->left=NewNode(2);
    tree->right=NewNode(3);
    tree->left->left=NewNode(4);
    tree->left->right=NewNode(5);
    tree->right->left=NewNode(6);
    tree->right->right=NewNode(7);*/
    
    tree=NewNode('A');
    tree->left=NewNode('B');
    tree->right=NewNode('C');
    tree->left->left=NewNode('D');
    tree->left->right=NewNode('E');
    tree->right->left=NewNode('F');
    tree->right->right=NewNode('G');
    tree->left->left->left=NewNode('H');
    tree->left->left->right=NewNode('I');
    tree->left->right->left=NewNode('J');
    tree->right->left->left=NewNode('K');
    tree->right->left->right=NewNode('L');
    tree->right->right->right=NewNode('M');

    printf("Height of the Tree: %d\n",Height(tree));
    printf("Depth/LEVEL of given node: %d\n",Depth(tree,tree->left->right,0));
    return 0;
}

