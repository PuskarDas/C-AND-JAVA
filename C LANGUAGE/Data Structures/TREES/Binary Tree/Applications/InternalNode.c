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
void InternalNode(struct Node *root) 
{
    struct Node *queue[100];  
    int front=0,rear=0;

    queue[rear++]=root;
    while(front<rear) 
    {
        struct Node *curr=queue[front++];
        int isInternal=0;

        if(curr->left) 
        {
            isInternal=1;
            queue[rear++]=curr->left;
        }
        if(curr->right) 
        {
            isInternal=1;
            queue[rear++]=curr->right;
        }
        if(isInternal)
            printf("%d, ",curr->a);
    }
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

    printf("\nAll Internal Nodes are :- ");
    InternalNode(tree);
    return 0;
} 