#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{ 
    int data;
    struct Node* next;
} Node;
Node *createNode(int data) 
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    if (!newNode) 
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Node *removeDuplicates(Node *head) 
{
    Node *current=head;
    while(current!=NULL && current->next!=NULL) 
    {
        if (current->data==current->next->data) 
        {
            Node* temp=current->next;
            current->next=current->next->next;
            free(temp);
        } 
        else 
            current=current->next;
    }
    return head;
}
void printList(Node* head) 
{
    Node* temp=head;
    while (temp!=NULL) 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() 
{
    Node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(2);
    head->next->next->next=createNode(3);
    printf("\n");
    printf("Original List: ");
    printList(head);
    printf("\n");
    head=removeDuplicates(head);
    printf("List after removing duplicates: ");
    printList(head);
    return 0;
}