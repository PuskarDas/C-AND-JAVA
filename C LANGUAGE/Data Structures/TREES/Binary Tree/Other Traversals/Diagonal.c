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
void Diagonal_Traversal(struct Node *root) 
{
    if(root==NULL)
        return;
    struct Node *queue[100]; 
    int front=0,rear=0;
    queue[rear++]=root;
    queue[rear++]=NULL; 
    
    while (front<rear) 
    {
        struct Node *curr=queue[front++];
        if(curr == NULL) 
        {
            if(front==rear) 
                break; 
            queue[rear++]=NULL; 
        } 
        else 
        {
            while(curr!=NULL) 
            {
                printf("%d, ",curr->a);
                if(curr->left != NULL)
                    queue[rear++]=curr->left;
                curr=curr->right;
            }
        }
    }
    printf("\n");
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

    printf("\n");
    Diagonal_Traversal(tree);
    return 0;
} 
