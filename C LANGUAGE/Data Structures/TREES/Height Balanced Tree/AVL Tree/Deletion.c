#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int a;
    struct Node *left;
    struct Node *right;
    int Height;
};
struct Node *NewNode(int x)
{
    struct Node *Node;
    Node=malloc(sizeof(struct Node));
    Node->a=x;
    Node->left=NULL;
    Node->right=NULL;
    Node->Height=1;
    return Node;
}
int Height(struct Node *root) 
{
    if(root==NULL)
        return 0;
    int left_Height=Height(root->left);
    int right_Height=Height(root->right);

    return(left_Height>right_Height?left_Height:right_Height)+1;
}
int Max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
struct Node *RightRotate(struct Node *y)
{
    struct Node *x=y->left;
    struct Node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->Height=Max(Height(y->left),Height(y->right))+1;
    x->Height=Max(Height(x->left),Height(x->right))+1;

    return x;
}
struct Node *LeftRotate(struct Node *x)
{
    struct Node *y=x->right;
    struct Node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->Height=Max(Height(x->left),Height(x->right))+1;
    y->Height=Max(Height(y->left),Height(y->right))+1;

    return y;
}
int GetBalance(struct Node *node)
{
    if(node==NULL)
        return 0;
    return Height(node->left)-Height(node->right);
}
struct Node *Insertion(struct Node *node,int key)
{
    if(node==NULL)
        return(NewNode(key));
    if(key<node->a)
        node->left=Insertion(node->left,key);
    else if(key>node->a)
        node->right=Insertion(node->right,key);
    else
        return node;
    
    node->Height=Max(Height(node->left),Height(node->right))+1;
    int balance=GetBalance(node);

    if(balance>1 && key < node->left->a) //Left-left Case
        return RightRotate(node);
    if(balance<-1 && key > node->right->a) //Right-Right Case
        return LeftRotate(node);
    if(balance>1 && key > node->left->a) //Left-Right Case
    {
        node->left=LeftRotate(node->left);
        return RightRotate(node);
    }
    if(balance<-1 && key < node->right->a) //Right-Left Case
    {
        node->right=RightRotate(node->right);
        return LeftRotate(node);
    }
    return node;
}
struct Node *MinNode(struct Node *node)
{
    struct Node *current=node;
    while(current->left!=NULL)
        current=current->left;
    return current;
}
struct Node *Deletion(struct Node *root,int key)
{
    //Standard BST Deletion of Node
    if(root==NULL)
        return root;
    if(key<root->a)
        root->left=Deletion(root->left,key);
    else if(key>root->a)
        root->right=Deletion(root->right,key); 
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
        struct Node *temp=MinNode(root);
        root->a=temp->a;
        root->right=Deletion(root->right,temp->a);
    }

    if(root==NULL)
        return root;
    //Update Height of current Node
    root->Height=Max(Height(root->left),Height(root->right))+1;
    int balance=GetBalance(root); //check for Balanced condition

    if(balance>1 && key < root->left->a) //Left-left Case
        return RightRotate(root);
    if(balance<-1 && key > root->right->a) //Right-Right Case
        return LeftRotate(root);
    if(balance>1 && key > root->left->a) //Left-Right Case
    {
        root->left=LeftRotate(root->left);
        return RightRotate(root);
    }
    if(balance<-1 && key < root->right->a) //Right-Left Case
    {
        root->right=RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}
struct Node *PreOrder(struct Node *root)
{
    if(root==NULL)
        return root;
    printf("%d, ",root->a);
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
    struct Node *tree=NULL;
    //tree=NewNode(50);
    tree=Insertion(tree,9);
    tree=Insertion(tree,5);
    tree=Insertion(tree,10);
    tree=Insertion(tree,0);
    tree=Insertion(tree,6);
    tree=Insertion(tree,11);
    tree=Insertion(tree,-1);
    tree=Insertion(tree,1);
    tree=Insertion(tree,2);

    printf("\nBefore Deletion:- ");
    PreOrder(tree);
    printf("\n");

    tree=Deletion(tree,10);
    printf("\nAfter Deletion:- ");
    PreOrder(tree);
    return 0;
}
