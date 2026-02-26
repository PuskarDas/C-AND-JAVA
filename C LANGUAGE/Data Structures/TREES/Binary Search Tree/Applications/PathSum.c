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
void PathSum(struct Node* root,int current_sum) 
{
    if(root==NULL) 
        return;
    current_sum+=root->a;
    if(root->left==NULL && root->right==NULL) 
    {
        printf("Path Sum : %d\n",current_sum);
        return;
    }
    PathSum(root->left,current_sum);
    PathSum(root->right,current_sum);
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

    printf("\nRoot-to-leaf path sums:-\n");
    PathSum(tree,0);
    return 0;
}
