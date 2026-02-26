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
struct Node *GetSuccessor(struct Node *curr) 
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}
struct Node *Deletion(struct Node *root,int x) 
{
    if(root==NULL)
        return root;

    if(x<root->a)
        root->left=Deletion(root->left,x);
    else if(x>root->a)
        root->right=Deletion(root->right,x); 
    else 
    {
        if(root->left==NULL) 
        {
            struct Node *temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL) 
        {
            struct Node *temp=root->left;
            free(root);
            return temp;
        }
        struct Node *succ=GetSuccessor(root);
        root->a=succ->a;
        root->right=Deletion(root->right,succ->a);
    }
    return root;
}
void InOrder(struct Node *root)
{
    if(root==NULL)
        return;
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
    printf("\nBefore Deletion:- ");
    InOrder(tree);
    printf("\n");

    int key=30;
    tree=Deletion(tree,key);
    printf("\nAfter Deletion:- ");
    InOrder(tree);
    return 0;
}