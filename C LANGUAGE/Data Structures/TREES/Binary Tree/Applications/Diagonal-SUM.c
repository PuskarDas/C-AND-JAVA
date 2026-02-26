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
void DiagonalSum(struct Node *root) 
{
    int diagonalSum[100]={0};
    int maxVD=0;

    struct Node *stack[100];
    int stackVD[100];
    int top=-1;
    stack[++top]=root;
    stackVD[top]=0;
    while(top>=0) 
    {
        struct Node *node=stack[top];
        int vd=stackVD[top--];
        while(node) 
        {
            diagonalSum[vd]+=node->a;
            if(vd>maxVD)
                maxVD=vd;
            if(node->left) 
            {
                stack[++top]=node->left;
                stackVD[top]=vd+1;
            }
        node=node->right;
        }
    }
    printf("\nDiagonal sum is: ");
    for (int i=0;i<=maxVD;i++) 
        printf("%d, ",diagonalSum[i]);
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

    DiagonalSum(tree);
    return 0;
} 