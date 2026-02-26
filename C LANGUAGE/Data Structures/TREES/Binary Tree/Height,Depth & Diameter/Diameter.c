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
int Diameter(struct Node *root) 
{
    if(root==NULL)
        return 0;
    int leftHeight=Height(root->left);
    int rightHeight=Height(root->right);

    int leftDiameter=Diameter(root->left);
    int rightDiameter=Diameter(root->right);

    return(leftHeight+rightHeight+1>leftDiameter && leftHeight+rightHeight+1>
          rightDiameter)?leftHeight+rightHeight+1: 
          (leftDiameter>rightDiameter?leftDiameter:rightDiameter);
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

    //printf("Height of the Tree: %d\n",Height(tree));
    printf("Diameter of the Tree: %d\n",Diameter(tree));
    return 0;
}