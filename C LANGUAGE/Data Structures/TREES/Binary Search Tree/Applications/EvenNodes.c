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
struct Node *Insertion(struct Node *root,int key)
{
    if(root==NULL)
        return NewNode(key);
    if(root->a==key)
        return root;
    if(root->a<key)
        root->right=Insertion(root->right,key);
    else
        root->left=Insertion(root->left,key);   
    return root;
}
void EvenNode(struct Node *root) 
{
    if(root!=NULL)
    { 
        EvenNode(root->left);
        if(root->a%2==0)
            printf("%d, ",root->a);
        EvenNode(root->right);
    }
}

int main()
{
    struct Node *tree=NULL;
    tree=Insertion(tree,5);
    tree=Insertion(tree,3);
    tree=Insertion(tree,2);
    tree=Insertion(tree,4);
    tree=Insertion(tree,7);
    tree=Insertion(tree,6);
    tree=Insertion(tree,8);

    printf("\nAll Even nodes are:- ");
    EvenNode(tree);
    return 0;
}