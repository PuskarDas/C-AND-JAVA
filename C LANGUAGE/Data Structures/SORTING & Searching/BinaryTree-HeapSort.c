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
void SWAP(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Max_Heap(struct Node *root)
{
    if(root==NULL)
        return;
    struct Node *largest=root;
     if(root->left && root->left->a > largest->a)
        largest=root->left;
    if(root->right && root->right->a > largest->a)
        largest=root->right;

    if(largest!=root) 
    {
        SWAP(&root->a,&largest->a);
        Max_Heap(largest);
    }
}
void Min_Heap(struct Node *root)
{
    if(root==NULL)
        return;
    struct Node *smallest=root;
     if(root->left && root->left->a < smallest->a)
        smallest=root->left;
    if(root->right && root->right->a < smallest->a)
        smallest=root->right;

    if(smallest!=root) 
    {
        SWAP(&root->a,&smallest->a);
        Min_Heap(smallest);
    }
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
    tree=NewNode(30);
    tree->left=NewNode(10);
    tree->right=NewNode(20);
    tree->left->left=NewNode(5);
    tree->left->right=NewNode(15);
    tree->right->left=NewNode(25);
    tree->right->right=NewNode(35);

    printf("Tree before Sorting :- \n");
    InOrder(tree);
    printf("\n");

    Max_Heap(tree);
    printf("Tree after Sorting in Increasing order :- \n");
    InOrder(tree);
    printf("\n");

    Min_Heap(tree);
    printf("Tree after Sorting in Decreasing order :- \n");
    InOrder(tree);
    printf("\n");
    return 0;
}
