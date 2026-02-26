#include<stdio.h>
#include <stdlib.h>
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
struct Node *PostOrder(struct Node *root)
{
    if(root==NULL)
        return root;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c, ",root->a);
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
    
    PostOrder(tree);
    printf("\n");
    return 0;
}
