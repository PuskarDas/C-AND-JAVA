#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *NewNode(int value)
{
    struct Node *Node;
    Node=malloc(sizeof(struct Node));
    Node->data=value;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
void Inorder(struct Node *root)
{
    if(root)
    {
        Inorder(root->left);
        printf("%d, ",root->data);
        Inorder(root->right);
    }
}
void Postorder(struct Node *root) 
{
    if(root)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d, ",root->data);
    }
}
void Preorder(struct Node *root) 
{
    if(root)
    {
        printf("%d, ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
struct Node *Insertion(struct Node *root,int key)
{
    if(root==NULL)
        return NewNode(key);
    /*if(root->data==key)
        return root;*/
    if(root->data<key)
        root->right=Insertion(root->right,key);
    else if(root->data>key)
        root->left=Insertion(root->left,key);   
    return root;
}
struct Node *GetSuccessor(struct Node *current) 
{
    current=current->right;
    while(current && current->left)
        current=current->left;
    return current;
}
struct Node *Deletion(struct Node *root,int key) 
{
    if(root==NULL)
        return root;
    if(key<root->data)
        root->left=Deletion(root->left,key);
    else if(key>root->data)
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
        struct Node *succ=GetSuccessor(root);
        root->data=succ->data;
        root->right=Deletion(root->right,succ->data);
    }
    return root;
}
struct Node *Search(struct Node *root,int key) 
{
    if(root==NULL || root->data==key)
        return root;
    else if(key<root->data)
        return Search(root->left,key);
    else
        return Search(root->right,key);
}
int findMin(struct Node *root) 
{
    if(root==NULL) 
        return -1;
    while(root->left)
        root=root->left;
    return root->data;
}
int findMax(struct Node *root) 
{
    if(root==NULL) 
        return -1;
    while(root->right)
        root=root->right;
    return root->data;
}
void DeleteTree(struct Node *root) 
{
    if(root) 
    {
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
    }
}
int main() 
{
    struct Node *root=NULL;
    int choice=-1,value;

    while(choice!=0) 
    {
        printf("--------Binary Search Tree Menu--------\n");
        printf("0. Quit\n");
        printf("1. Insert a Node\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Search\n");
        printf("6. Find Smallest Element\n");
        printf("7. Find Largest Element\n");
        printf("8. Deletion of Tree\n");
        printf("9. Delete a Node\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) 
        {
            case 0:
                printf("Exiting program\n");
                break;
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                root=Insertion(root,value);
                break;
            case 2:
                printf("In-order Traversal: ");
                Inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                Preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                Postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d",&value);
                if(Search(root,value))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 6:
                value=findMin(root);
                if(value!=-1)
                    printf("Smallest Element: %d\n",value);
                else
                    printf("Tree is empty\n");
                break;
            case 7:
                value=findMax(root);
                if(value!=-1)
                    printf("Largest Element: %d\n",value);
                else
                    printf("Tree is empty\n");
                break;
            case 8:
                DeleteTree(root);
                root=NULL;
                printf("Tree deleted\n");
                break;
            case 9:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                root=Deletion(root,value);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}