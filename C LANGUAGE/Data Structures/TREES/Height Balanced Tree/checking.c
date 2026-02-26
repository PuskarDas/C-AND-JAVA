#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
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
int Height(struct Node *root) 
{
    if (root==NULL)
        return -1;
    int left_Height=Height(root->left);
    int right_Height=Height(root->right);

    return(left_Height>right_Height?left_Height:right_Height)+1;
}
bool IsBalanced(struct Node *root)
{
    if(root==NULL)
        return true;
    int lheight=Height(root->left);
    int rHeight=Height(root->right);

    if(abs(lheight-rHeight)>1)
        return false;
    return IsBalanced(root->left) && IsBalanced(root->right);
}

int main()
{
    // Representation of input BST:
    //            1
    //           / \
    //          2   3
    //         /  \
    //        4   5 
    //       /
    //      8
    struct Node* tree=NewNode(1);
    tree->left=NewNode(2);
    tree->right=NewNode(3);
    tree->left->left=NewNode(4);
    tree->left->right=NewNode(5);
    //tree->left->left->left=NewNode(8);
    if (IsBalanced(tree))
        printf("TRUE !!\n");
    else
        printf("FALSE !!\n");
    return 0;
}
