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
int Search(struct Node *root,int x) 
{
    struct Node *curr=root;
    while(curr!=NULL) 
    {
        if(curr->a==x)
            return 1;    
        else if(curr->a<x) 
            curr=curr->right;
        else
            curr=curr->left;
    }
    return 0;
}
void InOrder(struct Node *root)
{
    if(root==NULL)
        return;
    InOrder(root->left);
    printf("%d, ",root->a);
    InOrder(root->right);
}
/*void displayTree() 
{
    printf("\n");
    printf("        50\n");
    printf("       /  \\\n");
    printf("     30    70\n");
    printf("    /  \\   /  \\\n");
    printf("   20   40 60  80\n");
    printf("\n");
}*/
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
    
    int x=40;
    if(Search(tree,x))
        printf("FOUND !!");
    else
        printf("NOT FOUND !!");
    return 0;

    /*displayTree();
    
    int x=40;
    if (x==50 || x==30 || x==70 || x==20 || x==40 || x==60 || x==80) 
        printf("FOUND !!\n");
    else 
        printf("NOT FOUND !!\n");
    return 0;*/
}



