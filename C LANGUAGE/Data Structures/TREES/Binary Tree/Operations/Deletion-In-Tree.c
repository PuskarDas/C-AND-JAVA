#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char a;
    struct Node *left;
    struct Node *right;
};
struct Node *NewNode(char x)
{
    struct Node *Node;
    Node=malloc(sizeof(struct Node));
    Node->a=x;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
void DeleteDeepest(struct Node* root,struct Node *DelNode) 
{
    struct Node *queue[100];
    int front=0,rear=0;
    queue[rear++]=root;

    while(front<rear) 
    {
        struct Node *temp=queue[front++];
        
        if(temp==DelNode) 
        {
            temp=NULL;
            free(DelNode);
            return;
        }
        
        if (temp->right!=NULL) 
        {
            if (temp->right==DelNode) 
            {
                temp->right=NULL;
                free(DelNode);
                return;
            }
            queue[rear++]=temp->right;
        }
        if(temp->left!=NULL) 
        {
            if(temp->left==DelNode) 
            {
                temp->left=NULL;
                free(DelNode);
                return;
            }
            queue[rear++]=temp->left;
        }
    }
}
struct Node* Deletion(struct Node* root,char key) 
{
    if (root==NULL)
        return NULL;

    if (root->left==NULL && root->right==NULL) 
    {
        if (root->a==key)
            return NULL;
        else
            return root;
    }
    struct Node *queue[100];
    char front=0,rear=0;
    queue[rear++]=root;

    struct Node *keyNode=NULL;
    struct Node *temp;
    while (front<rear) 
    {
        temp=queue[front++];
        if(temp->a==key)
            keyNode=temp;
        if(temp->left)
            queue[rear++]=temp->left;
        if(temp->right)
            queue[rear++]=temp->right;
    }
    if (keyNode!=NULL) 
    {
        char x=temp->a;
        keyNode->a=x;
        DeleteDeepest(root,temp);
    }
    return root;
}
struct Node *InOrder(struct Node *root)
{
    if(root==NULL)
        return root;
    InOrder(root->left);
    printf("%c, ",root->a);
    InOrder(root->right);
}
int main()
{
    struct Node *tree=NULL;
    /*tree=NewNode(1);
    tree->left=NewNode(2);
    tree->right=NewNode(3);
    tree->left->left=NewNode(4);
    tree->left->right=NewNode(5);
    tree->right->left=NewNode(6);
    tree->right->right=NewNode(7);*/

    tree=NewNode('A');
    tree->left=NewNode('B');
    tree->right=NewNode('C');
    tree->left->left=NewNode('D');
    tree->left->right=NewNode('E');
    tree->right->left=NewNode('F');
    tree->right->right=NewNode('G');
    tree->left->left->left=NewNode('H');
    tree->left->left->right=NewNode('I');
    tree->left->right->left=NewNode('J');
    tree->right->left->left=NewNode('K');
    tree->right->left->right=NewNode('L');
    tree->right->right->right=NewNode('M');
    printf("\nTree before Deletion:- ");
    InOrder(tree);
    printf("\n");
    int key='I';
    Deletion(tree,key);
    printf("\nTree after Deletion:- ");
    InOrder(tree);
    return 0;
}
