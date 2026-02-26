#include<stdio.h>
#include<stdlib.h>
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
struct Node *InOrder(struct Node *root)
{
    if(root==NULL)
        return root;
    InOrder(root->left);
    printf("%d, ",root->a);
    InOrder(root->right);
}

int main()
{
    struct Node *tree=NULL;
    tree=NewNode(50);
    tree=Insertion(tree,30);
    tree=Insertion(tree,20);
    tree=Insertion(tree,40);
    tree=Insertion(tree,70);
    tree=Insertion(tree,60);
    tree=Insertion(tree,80);

    InOrder(tree);
    printf("\n");
    return 0;
}